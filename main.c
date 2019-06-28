#include "headers.h"
#include "prototype.h"

int main(void)
{
	system("clear");
	int gsmHandle = 0;                  
	int returnValue = 0;                    
	char termNumber[16] = {0};
	char messageRecieved[160] = {0};
	char dateTimeStamp[21] = {0};
	char IMEINumber[IMEI_NUMBER_MAX_LENGTH + 1] = {0};
	char manufacturerName[100] = {0};
	char modelNumber[100] = {0};
	char networkProvider[50] = {0};
	char signalStrength[4] = {0};
	int SimStatus = 0;
	int networkStatus = 0;
	int choice =0;
	int option =0;
	char date[DATE_MAX_LENGTH + 1] = {0};
	char time[TIME_MAX_LENGTH + 1] = {0};
	int senderPhoneNumber;
	int smscNumber=0;
	
	while(1)
	{
		choice = mainmenu();
		sleep(1);
		switch(choice)
		{
			case 1:

				/// Configure COM port for opem GSM modem
				printf("Check port is open \n");
				returnValue = GsmOpen(&gsmHandle, 9600);
				if (returnValue == FALSE)
				{
					printf("cannot open port \n");
					getchar();
					return 0;
				}
				break;
			case 2 :
				///  Check communication with modem
				printf("Check communication with modem\n");
				returnValue = SendATCommand(gsmHandle, "AT", TRUE, "OK");    
				if (returnValue == FALSE)
				{
					printf("cannot communication with modem \n");
					getchar();
					return 0;
				}	
				break ;
			case 3 :
				/// IMEI number 
				printf("IMEINumber \n");
				returnValue = GsmGetIMEINumber(gsmHandle, IMEINumber);
				if (returnValue == FALSE)
				{
					printf("error in obtaining IMEI number \n");
					getchar();
					return 0;
				}
				printf(" IMEI = %s\n", IMEINumber);
				break ;
			case 4 :
				/// MANUFACTURER
				returnValue = GsmGetManufacturerInfo(gsmHandle, manufacturerName, modelNumber);
				if (returnValue == FALSE)
				{
					printf("error in obtaining manufacturer information \n");
					getchar();
					return 0;
				}
				printf("Manufacturer Name:---->%s\n", manufacturerName);
				printf("**********************************************\n");
				printf("Model Number :-------->%s\n", modelNumber);
				break ;
			case 5 :
				/// SIM STATUS 
				printf("SIM STATUS \n");
				returnValue = GsmGetSIMStaus(gsmHandle, &SimStatus); 
				if (returnValue == FALSE)
				{
					printf("error to obtain SIM status\n");
					getchar();
					return 0;
				}
				break ;
			case 6 :
				/// SIGNAL STRENTH 
				printf("SIGNAL STRENGTH \n");
				returnValue = GsmGetSignalStength(gsmHandle, signalStrength);
				if (returnValue == FALSE)
				{
					getchar();
					return 0;
				}
				printf(" Signal Strength = %s \n", signalStrength);
				break ;
			case 7 :
				/// N/W REGISTRATION
				printf("N/W REGISTRATION \n");
				returnValue = GsmGetNetworkRegistrationSIMStaus(gsmHandle, &networkStatus, networkProvider); 
				if (returnValue == FALSE)
				{
					getchar();
					return 0;
				}
				printf(" Network Status = %d, Network Provider = %s \n", networkStatus, networkProvider);
				break ;
			case 8 :
				/// Example to send SMS
				returnValue = SendATCommand(gsmHandle, "AT+CMGF=1", TRUE, "OK");
				if (returnValue == FALSE)
				{
					printf("cannot set to text mode \n");
					getchar();
					return FALSE;
				}
				printf("SENDING MESSGAE \n");
				returnValue = GsmSendSms(gsmHandle);
				if (returnValue == FALSE)
				{
					printf("cannot send message \n");
					getchar();
					return 0;
				}
				break ;
			case 9:
				// Example of message Center number 
				printf(" Message Center Number\n");
				returnValue = GsmGetMessageCenterNumber(gsmHandle,&smscNumber);
				if (returnValue == FALSE)
				{
					printf("cannot got SMSC number  \n");
					getchar();
					return 0;
				}
				break ;
			case 10:
				// Example of check ALL message  in SIM card 
				printf("Example of check ALL message in sim card \n");
				returnValue=SendATCommand(gsmHandle, "AT+CMGL=\"ALL\"", TRUE, "OK");
				if (returnValue == FALSE)
				{
					printf("cannot got all sms \n");
					getchar();
					return 0;
				}

				break ;
			case 11:
				// Example of Delete  message  from SIM card
				gsmdelsms(gsmHandle); 
				break ;

			case 0:
				system("make clean");
				system("clear");
				system("ls");
				GsmClose(gsmHandle);         ///< Free resources allocated 
				exit(0);
				break;

			default :

				printf("Invalid Choice \n");

		}
	}
	GsmClose(gsmHandle);         ///< Free resources allocated 
	return TRUE;
}
