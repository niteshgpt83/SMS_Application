#include "headers.h"
#include "prototype.h"

int gsmdelsms(int port)
{
	// Example of Delete  message  from SIM card
	system("clear");
	int option; 
	while(1)
	{
		option=delsmsmenu();
		switch(option)
		{

			case 1:
				delonesms(port);
				break;
			case 0:
				main();
				break;
			default :
				printf("Invalid Choice in Deletesms\n");

		}
	}

	return 0;
}
