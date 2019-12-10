#include <stdlib.h>
#include "num_recog.h"
#include "calc_gen.h"

int main()
{
   unsigned result = 0, select = 0;
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

   select = calc_gen();

//   printf("\n operacao = %d \n", oper_select);

   timeout = false;
   do
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
   while(!timeout && select == 0);
   }
   while(1);

   return 0;
}
