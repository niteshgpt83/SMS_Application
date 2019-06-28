#include "headers.h"
#include "prototype.h"


int delonesms(int port)
{
	system("clear");
	int returnValue = 0;
	returnValue = SendATCommand(port, "AT+CMGF=1", TRUE, "OK");
	if (returnValue == FALSE)
	{
		printf("cannot set to text mode \n");
		getchar();
		return FALSE;
	}
	returnValue = SendATCommand(port, "AT+CMGL=\"ALL\"", TRUE, "OK");
	if (returnValue == FALSE)
	{
		printf("cannot show all message \n");
		getchar();
		return FALSE;
	}
	int choice;
		
        printf("+*************************************************************************+\n");
	printf("|                                                                        +|\n");
	printf("|                      please type index number                          +|\n");
	printf("|                                                                        +|\n");
        printf("+*************************************************************************+\n");
	printf("                      0. Press  to go mainmenu                           +|\n");
        printf("+*************************************************************************+\n");
	printf("Enter Index Number to Delete Message +CMGL:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			SendATCommand(port, "AT+CMGD=1", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 1 Message is deleted :\n");
			printf("******************************");
			break;
		case 2:
			SendATCommand(port, "AT+CMGD=2", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 2 Message is deleted :\n");
			printf("******************************");
			break;
		case 3 :
			SendATCommand(port, "AT+CMGD=3", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 3 Message is deleted :\n");
			printf("******************************");
			break;
		case 4 :
			SendATCommand(port, "AT+CMGD=4", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 4 Message is deleted :\n");
			printf("******************************");
			break;
		case 5 :
			SendATCommand(port, "AT+CMGD=5", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 5 Message is deleted :\n");
			printf("******************************");
			break;
		case 6 :
			SendATCommand(port, "AT+CMGD=6", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 6 Message is deleted :\n");
			printf("******************************");
			break;
		case 7 :
			SendATCommand(port, "AT+CMGD=7", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			break;
		case 8 :
			SendATCommand(port, "AT+CMGD=8", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 8 Message is deleted :\n");
			printf("******************************");
			break;
		case 9 :
			SendATCommand(port, "AT+CMGD=9", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 9 Message is deleted :\n");
			printf("******************************");
			break;

		case 10:
			SendATCommand(port, "AT+CMGD=10", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 10 Message is deleted :\n");
			printf("******************************");
			break;
		case 11 :
			SendATCommand(port, "AT+CMGD=11", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 11 Message is deleted :\n");
			printf("******************************");
			break;
		case 12 :
			SendATCommand(port, "AT+CMGD=12", TRUE, "OK");
			if (returnValue == FALSE)
			{
				printf("error \n");
				getchar();
				return FALSE;
			}
			printf("Index 12 Message is deleted :\n");
			printf("******************************");
			break;
		case 0:
			system("clear");
			main();
			break;

		default :
			printf("Invalid Index Number\n");

	}
	return 0;
}
