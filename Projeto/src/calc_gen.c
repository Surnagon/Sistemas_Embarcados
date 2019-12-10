#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned select, oper_select;
bool timeout;



srand((unsigned)time(NULL));   // Initialization, should only be called once.
   
int a, b;


select = 0;

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
         printf("\r\n opcao invalida %d", result);
         printf("\r\n");
         break;
   }
