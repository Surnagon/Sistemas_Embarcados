#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "num_recog.h"

int main()
{
   unsigned result, select, oper_select;
   bool timeout;
   char charbuffer[124];
   int ret;
   unsigned * rd;

   T_numrecog_cotext context;
   T_numrecog_info buffer[10];

   do
   {
      ret = numrecog_start(&context,5000,1000,buffer,10,"recogfile",
                        charbuffer,sizeof(charbuffer));
   if(ret)
   {
      printf("\r\n Erro ao iniciar");
      return 0;
   }

   result = 0;
   /*result = calc_gen()*/
   srand((unsigned)time(NULL));   // Initialization, should only be called once.
   
   int a, b;
   
   oper_select = (rand() % (4)) + 1;
   printf("\n operacao = %d \n", oper_select);
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

   timeout = false;
   while(!timeout && select != 0)
   {
      rd = numrecog_read(&context,&result,&timeout);
      if(rd!=NULL)
      {
         printf("\r\n %d, certo?", result);
         printf("\r\n");
         if(result == select)
         {
            printf("\r\n PARABENS!!! \n Voce acertou!");
            printf("\r\n");
         }
         else
         {
            printf("\r\n Que pena. Voce errou. A resposta correta era %d", select);
            printf("\r\n");
         }
         break;
      }
      else
      {
         if(timeout)
         {
            printf("\r\n a crianca  nao respondeu");
         }
         else
         {
//                  printf("\r\n a crianca nao respondeu ainda");
         }
      }
   }
   }while(1);
   return 0;
}
