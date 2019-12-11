#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "calc_gen.h"

#define CALC_GEN_HIGHEST_NUM (10)

void calc_gen_start()
{
        // Initialization, should only be called once.
	srand((unsigned)time(NULL));
}

unsigned calc_gen()
{
	unsigned select, oper_select;
	int a, b;

	oper_select = (rand() % (4)) + 1;
         
   a = (rand() % (CALC_GEN_HIGHEST_NUM))+1;
   b = (rand() % (CALC_GEN_HIGHEST_NUM))+1;
	
   switch(oper_select)
   {
      case 1:
         select = a+b;
         printf("\r\n %d + %d", a, b);
         printf("\r\n");
         break;
      case 2:
         select = abs(a-b);
         printf("\r\n %d - %d", (a>b)?a:b, a>b?b:a);
         printf("\r\n");
         break;
      case 3:
         select = a*b;
         printf("\r\n %d X %d", a, b);
         printf("\r\n");
         break;
      case 4:
         a = a*b;
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

