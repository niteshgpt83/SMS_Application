#include "headers.h"
#include "prototype.h"

int password()
{
	char name[20];
	char password[10];
	printf("+***********************************************************************+\n");
	printf("+             Enter username and password for log SMS_Application        \n");
	printf("+***********************************************************************+\n");
	printf("Enter username: ");
	scanf("%s",name);
	printf("Enter password: ");
	scanf("%s",password);
	if (strcmp(name, "nitesh") == 0 && strcmp(password, "aelinux") == 0)
	{
		printf("\t\t\t\t+***********************************************************************+\n");
		printf("\t\t\t\t+                   Welcome to SMS application                          +\n");
		printf("\t\t\t\t+***********************************************************************+\n");
		return TRUE;
	}
	else
	{	printf("Access denied\n");	
		return 0;
	}
}
