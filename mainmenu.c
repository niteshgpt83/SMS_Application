#include "headers.h"
#include "prototype.h"


int mainmenu()
{
	int choice;
	printf("\t\t\t\t                                                                          \n");
	printf("\t\t\t\t                                                                          \n");
	printf("\t\t\t\t                                                                          \n");
	printf("\t\t\t\t +***********************************************************************+\n");
	printf("\t\t\t\t |                          Serial Port mainmenu                         |\n");
	printf("\t\t\t\t +***********************************************************************+\n");
	printf("\t\t\t\t +                      1.Opem GSM modem  port                           +\n");
	printf("\t\t\t\t +                      2.Check communication with modem                 +\n");
	printf("\t\t\t\t +                      3.Check IMEI number                              +\n");
	printf("\t\t\t\t +                      4.Check MANUFACTURER and Model                   +\n");
	printf("\t\t\t\t +                      5.Check SIM STATUS                               +\n");
	printf("\t\t\t\t +                      6.check SIGNAL STRENTH                           +\n");
	printf("\t\t\t\t +                      7.N/W REGISTRATION                               +\n");
	printf("\t\t\t\t +                      9.Check message Center number                    +\n");
	printf("\t\t\t\t +                      10.Check ALL message sim card                    +\n");
	printf("\t\t\t\t +                      11.Delete messages from  sim card                +\n");
	printf("\t\t\t\t +                      0.Exit                                           +\n");
	printf("\t\t\t\t +***********************************************************************+\n");
	printf("\t\t\t\t                                                                          \n");
	printf("\t\t\t\t                                                                          \n");
	printf("\t\t\t\t                                                                          \n");
	printf("\t\t\t\t                     Enter the choice:");
	scanf("%d",&choice);
	return choice;
}
