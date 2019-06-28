#include "headers.h"
#include "prototype.h"

int delsmsmenu()
{
        int choice;
        printf("\t\t\t\t+*******************************************************************+\n");
	printf("\t\t\t\t|                                                                  +|\n");
        printf("\t\t\t\t|                Serial Port DeleteMenu                            +|\n");
	printf("\t\t\t\t|                                                                  +|\n");
        printf("\t\t\t\t+****************************************************************** +\n");
        printf("\t\t\t\t1.               Delete One bY One  message                         +\n");
        printf("\t\t\t\t0.               Go to main manu                                    +\n");
        printf("\t\t\t\t+*******************************************************************+\n");
        printf("\t\t\t\t                Enter the choice:");
        scanf("%d",&choice);
        return choice;
}
