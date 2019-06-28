#include "headers.h"
#include "prototype.h"

/// Configure COM port for opem GSM modem
//////////////////////////////////////////////////////////////////////////////////////////////////
int GsmOpen(int *port ,int baudRate)
{

	struct termios settings;
	int fd = open("/dev/ttyUSB0", O_RDWR);
	int type  = 0;
	if (fd == -1)
	{
		printf("Failed to open serial interface\n");
		goto error;

	}
	tcgetattr(fd, &settings);
	cfmakeraw(&settings);
	settings.c_cflag &= ~(PARENB | CSTOPB | CSIZE); /* no parity, 1 stop bit */
	settings.c_cflag |= CS8 | CLOCAL | CREAD; /* 8 bits */
	if (type == 1)
	{
		settings.c_cflag |= ICANON;
		settings.c_cc[VTIME] = 2; /* 200 millisec */
		settings.c_cc[VMIN] = 0;

	}
	else if(type == 0)
	{
		settings.c_cc[VTIME] = 7; /* 900 millisecond */
		settings.c_cc[VMIN] = 200;

	}
	settings.c_oflag &= ~OPOST; /* raw output */
	cfsetspeed(&settings, baudRate); /* baud rate */
	tcsetattr(fd, TCSANOW, &settings); /* apply the settings */
	tcflush(fd, TCOFLUSH);
	tcflush(fd, TCIFLUSH);
	*port = fd;//open(fd, "w");
	printf("port is sucessfully open :/dev/ttyUSB0\n");
error:
	return fd;
}
///  Check communication with modem
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int SendATCommand(int port, char *commandString, int terminate, char *responseString)

{

	int timeOut = 50;            ///< 2.5 Seconds + fread Delay
	int noOfBytesRead = 0;  
	int bytesTransmitted = 0;
	char readBuffer[100] = {0};
	bytesTransmitted = write(port,commandString, strlen(commandString));   ///< Send command to GSM modem 
	if (terminate == 1)
		bytesTransmitted = write(port,"\r\n", 2);
	if (responseString == NULL)
	{
 		return TRUE;

	}
	while (timeOut)                ///< If response to command is expected
	{

		memset(readBuffer, 0, 100);
		noOfBytesRead = read(port, readBuffer, 100);
	        printf("%s\n",readBuffer);
		if (strstr(readBuffer, responseString))
		{
			return TRUE;

		} else if(strstr(readBuffer, "NO"))
		{

			return FALSE;
		}
		else
		{
			usleep(50);

		}
		timeOut--;
	}
	return FALSE;

}
/// IMEI number
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmGetIMEINumber(int port, char *imeiNumber)
{
	int noOfBytesTransmitted = 0;
	int noOfBytesRead = 0;
	char readBuffer[32] = {0};

	noOfBytesTransmitted = write(port, "AT+CGSN\r\n", 8);
	usleep(250);
	noOfBytesRead = read(port, readBuffer, 32);   ///< Receive IMEI number in response
	if (noOfBytesRead >= IMEI_NUMBER_MAX_LENGTH + 2)
	{
		strncpy(imeiNumber, readBuffer + 2, IMEI_NUMBER_MAX_LENGTH); 
		return TRUE;
	}
	else
	{
		return FALSE; 
	}
}
/// MANUFACTURER
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmGetManufacturerInfo(int port, char *manufacturer, char *modelNumber)
{
//	system("clear");
	int noOfBytesTransmitted = 0;
	int noOfBytesRead = 0;
	char readBuffer[100] = {0};
	noOfBytesTransmitted = write(port, "AT+CGMI\r\n", 9);
	usleep(250);
	noOfBytesRead = read(port, readBuffer, 100);    ///< Get manufacturer information in response
	if (noOfBytesRead == 0)
	{
		return FALSE;
	}
	else
	{
		strncat(manufacturer, readBuffer + 2, strlen(readBuffer)- 10);
	}

	noOfBytesTransmitted = write(port, "AT+CGMM\r\n", 9);
	usleep(250);
	noOfBytesRead = read(port, readBuffer, 100);   ///< Get model identification in response
	if (noOfBytesRead == 0)
	{
		return FALSE;
	}
	else
	{
		strncat(modelNumber,readBuffer + 2, strlen(readBuffer)- 10); 
		return TRUE;
	}
}
/// SIM STATUS 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmGetSIMStaus(int port, int *status)
{
	if (!SendATCommand(port, "AT+CPIN?", TRUE, "+CPIN"))		///< Check if SIM is inserted and if PIN required
	{
		return FALSE;
	}
	return TRUE;
}
/// SIGNAL STRENTH
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmGetSignalStength(int port, char *signalStrength)
{
	int noOfBytesTransmitted = 0;
	int noOfBytesRead = 0;
	int length = 0;
	char readBuffer[100] = {0};
	char *start = NULL;
	char *end = NULL;

	noOfBytesTransmitted = write(port, "AT+CSQ\r\n", 8);
	usleep(250);
	noOfBytesRead = read(port, readBuffer, 100);   ///< Get network signal strength
	if (noOfBytesRead == 0)
	{
		return FALSE;
	}
	else
	{
		start = strstr(readBuffer, ": ");
		end = strstr(start + 1, ",");
		if (!start || !end)
		{
			return FALSE;
		}
		length = end - (start + 2);
		strncat(signalStrength, (start + 2), length);
		return TRUE;
	}
}
/// N/W REGISTRATION
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmGetNetworkRegistrationSIMStaus(int port, int *status, char *networkProvider)
{
	int noOfBytesTransmitted = 0;
	int noOfBytesRead = 0;
	int length = 0;
	char readBuffer[100] = {0};
	char start = 0;
	char *star = NULL;
	char *end = NULL;

	*status = SendATCommand(port, "AT+CREG?", TRUE, "+CREG: 0,1");   ///< Check registration status

	if (*status == 1)
	{	    	
		noOfBytesTransmitted = write(port, "AT+COPS?\r\n", 10);
		usleep(250);
		noOfBytesRead = read(port, readBuffer, 100);   ///< Get network information 
		if (noOfBytesRead == 0)
		{
			return FALSE;
		}
		else
		{
			star = strstr(readBuffer, ",");
			end = strstr(star + 1, ",");
			if (!star || !end)
			{
				return FALSE;
			}
			length = strlen(end) - strlen(star+1);
			strncat(networkProvider, star+1, length);
			return TRUE;
		}
	}
	else
	{
		return FALSE;
	}
}
/// Example to send SMS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmSendSms(int port)
{
	int returnValue = 0;
	returnValue = SendATCommand(port, "AT+CMGS=\"", FALSE, 0);
	returnValue = SendATCommand(port, "+9194540373558", FALSE, 0);
	returnValue = SendATCommand(port, "\"", TRUE, ">");
	write(port,"hello", 6);
	sleep(1);
	write(port, "26", 2);	
}
/// Example to receive SMS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmRecieveSms(int port, char *messageIndex, char *senderPhoneNumber, char *dateTimeStamp, char *message, int messageSize)
{
	int returnValue = 0;
	char readBuffer[256] = {0}; 
	int bytesRead = 0;
	returnValue = SendATCommand(port, "AT+CMGR=", FALSE, NULL);
	returnValue = SendATCommand(port, messageIndex, TRUE, NULL);
	bytesRead = read(port, readBuffer, 256); 
	usleep(1000);
	if (!strstr(readBuffer, "+91"))
	{
		return FALSE;
	}
	strncat(senderPhoneNumber, strstr(readBuffer, "+91"), 13);    ///< Phone number string length = 13, +919454037558
	strncat(dateTimeStamp, strstr(readBuffer, "/") - 2, 20);      ///< Date time string length = 20, "12/12/24,18:08:44+22" "YY/MM/DD,HH:MM+SS"
	strncat(message, strstr(readBuffer, "/") + 18, 160);
	message[strlen(message) - 1] = 0;
	message[strlen(message) - 2] = 0;
	message[strlen(message) - 3] = 0;
	return TRUE;
}
// Example of message Center number
int GsmGetMessageCenterNumber(int port,int *smscNumber)
{

	if (!SendATCommand(port, "AT+CSCA?", TRUE, "+CSCA"))     
	{
		return FALSE;
	}
	return TRUE;

}
//close port
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GsmClose( int port)
{
	if(port == 0)
	{
		return FALSE;
	}

	close(port);
	port = 0;
	return TRUE;
}
