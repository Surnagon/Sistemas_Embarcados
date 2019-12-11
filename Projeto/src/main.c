#include <stdlib.h>
#include <string.h>
#include "num_recog.h"
#include "calc_gen.h"


#define NO_ANS_TIMEOUT_MS (10000)
#define ANS_COMPLETION_TIMEOUT (3000)


#define voice_wrong_ans(_num,_str) \
do\
{ \
   sprintf(_str,"espeak -v pt-br \"Que pena voce errou a resposta correta era %d\"",_num); \
   system(_str); \
}while(0)

#define voice_right_ans() do{ system("espeak -v pt-br \"PARABENS. Voce acertou. \"");}while(0)
#define voice_no_ans() do{ system("espeak -v pt-br \"Voce nao respondeu. \"");}while(0)


int main()
{
   unsigned result = 0, select = 0;
   bool timeout;
   char charbuffer[124];
   char voice_str[124];
   int ret;
   unsigned * rd;

   T_numrecog_cotext context;
   T_numrecog_info buffer[10];
   system("espeak -v pt \"configurando voz\"");
   do
   {
      ret = numrecog_start(&context,NO_ANS_TIMEOUT_MS,ANS_COMPLETION_TIMEOUT,buffer,
                           sizeof(charbuffer)/sizeof(charbuffer[0]),"recogfile",
                           charbuffer,sizeof(charbuffer));
      if(ret)
      {
         printf("\r\n Erro ao iniciar");
         return 0;
      }

      select = calc_gen();

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
               printf("\r\n PARABENS! RESPOSTA CORRETA!!");
               printf("\r\n");
               voice_right_ans();
            }
            else
            {
               printf("\r\n Que pena. Voce errou. A resposta correta era %d", select);
               printf("\r\n");
               voice_wrong_ans(select,voice_str);
            }
            break;
         }
         else
         {
            if(timeout)
            {
               printf("\r\n a crianca  nao respondeu");
               voice_no_ans();
            }
         }
      }
      while((!timeout) && (select));

   }
   while(1);

   return 0;
}
