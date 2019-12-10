#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "calc_gen.h"

void calc_gen_start()
{
        // Initialization, should only be called once.
	srand((unsigned)time(NULL));
}

unsigned calc_generate()
{
	unsigned select, oper_select;
	int a, b;

	oper_select = (rand() % (4)) + 1;
	
   switch(oper_select)
   {
      case 1:
         a = (rand() % (11));
         b = (rand() % (11));
         select = a+b;
         printf("\r\n %d + %d", a, b);
         printf("\r\n");
         break;
      case 2:
         do
         {
         a = (rand() % (11));
         b = (rand() % (11));
         }while(a < b);
         select = a-b;
         printf("\r\n %d - %d", a, b);
         printf("\r\n");
         break;
      case 3:
         a = (rand() % (11));
         b = (rand() % (11));
         select = a*b;
         printf("\r\n %d X %d", a, b);
         printf("\r\n");
         break;
      case 4:
         do
         {
         a = (rand() % (11));
         b = (rand() % (11));
         }while(a%b != 0);
         select = a/b;
         printf("\r\n %d / %d", a, b);
         printf("\r\n");
         break;
      default:
         printf("\r\n Houve um erro. Opcao invalida. Tente novamente");
         printf("\r\n");
         break;
   }
   return select;
}

