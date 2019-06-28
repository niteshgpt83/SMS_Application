#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

int mainmenu(); 
//******************************************************************************
/// Configure COM port to communicate with GSM modem
/// @param[out]    port           COM port for GSM modem 
/// @param[in]     baudRate       Baudrate for communication
/// @retval        TRUE           Success
///                FALSE          Failure
int GsmOpen(int *port,int baudRate);
 
//******************************************************************************
/// Send SMS to a phone number
/// @param[in]     port              GSM Port Handle returned by call to GsmOpen().
/// @param[in]     phoneNumber       Phone number to which SMS is send
/// @param[in]     message           Message to send in SMS
/// @param[out]    deliveryReport    Message delivery report
/// @retval        TRUE              Success
///                FALSE             See GetLastError()
int GsmSendSms(int port);
 
//******************************************************************************
/// Read received SMS
/// @param[in]     port                 GSM Port Handle returned by call to GsmOpen().
/// @param[in]     messageIndex         Index of received SMS
/// @param[out]    senderPhoneNumber    SMS sender phone number
/// @param[out]    dateTimeStamp        Date and time of received SMS
/// @param[out]    message              Message received in SMS
/// @param[in]     messageSize          Message size
/// @retval        TRUE                 Success
///                FALSE                Failure
int GsmRecieveSms(int port, char *messageIndex, char *senderPhoneNumber, char *dateTimeStamp, char *message, int messageSize);
 
//******************************************************************************
/// Close COM port used for GSM modem
/// @param[in]     port           GSM Port Handle returned by call to GsmOpen().
/// @retval        TRUE           Success
///                FALSE          Failure
int GsmClose(int port);
 
//******************************************************************************
/// Send AT command to GSM modem
/// @param[in]    port             GSM Port Handle returned by call to GsmOpen().
/// @param[in]    commandString    AT command to be send
/// @param[in]    terminate        End of message
/// @param[in]    responseString   Expected AT command response
/// @retval       TRUE             Success
///               FALSE            Failure
int SendATCommand(int port, char *commandString, int terminate, char *responseString);
 
//******************************************************************************
/// Gets IMEI number of the modem
/// @param[in]    port           GSM Port Handle returned by call to GsmOpen().
/// @param[out]   imeiNumber     IMEI number of the device
/// @retval       TRUE           Success
///               FALSE          Failure
int GsmGetIMEINumber(int port, char *imeiNumber);
 
//******************************************************************************
/// Gets information about modem manufacturer
/// @param[in]    port           GSM Port Handle returned by call to GsmOpen().
/// @param[out]   manufacturer   Manufacturer information
/// @param[out]   modelNumber    Model number of modem
/// @retval       TRUE           Success
///               FALSE          Failure
int GsmGetManufacturerInfo(int port, char *manufacturer, char *modelNumber);
 
//******************************************************************************
/// Gets SIM pin status
/// @param[in]    port           GSM Port Handle returned by call to GsmOpen().
/// @param[out]   status         SIM status
/// @retval                      Returns the status of SIM
int GsmGetSIMStaus(int port, int *status);
 
//******************************************************************************
/// Gets information of SIM registration and network provider 
/// @param[in]    port                GSM Port Handle returned by call to GsmOpen().
/// @param[out]   status              Status of SIM registration 
/// @param[out]   networkProvider     Network provider information
/// @retval       TRUE                Success
/// @retval       FALSE               Failure
int GsmGetNetworkRegistrationSIMStaus(int port, int *status, char *networkProvider);
 
//******************************************************************************
/// Gets signal strength information
/// @param[in]    port              GSM Port Handle returned by call to GsmOpen().
/// @param[out]   signalStrength    signal strength information
/// @retval       TRUE              Success
///               FALSE             Failure
int GsmGetSignalStength(int port, char *signalStrength);
 
//******************************************************************************
/// Gets Network Date and Time Information
/// @param[in]   port           GSM Port Handle returned by call to GsmOpen().
/// @param[out]  date           Pointer to date string
/// @param[out]  time           Pointer to time string
/// @retval      TRUE           Success
///              FALSE          Failure
int GsmGetNetworkDateTimeInformation(int port, char *date, char *time);

int GsmGetMessageCenterNumber(int port,int *smscNumber);
int delonesms(int port);
int delsmsmenu();
int gsmdelsms(int port);
int main();
int password();
#endif // _GSMMODEM_H_
