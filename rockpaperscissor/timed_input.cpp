#include <sys/time.h>
#include <stdio.h>

int main()
{
   fd_set fdset;
   struct timeval timeout;
   int  rc;
   int  val;

   timeout.tv_sec = 6;   /* wait for 6 seconds for data */
   timeout.tv_usec = 0;


   FD_ZERO(&fdset);

   FD_SET(0, &fdset);

   rc = select(1, &fdset, NULL, NULL, &timeout);
   if (rc == -1)  /* select failed */
   {
       printf("ERROR path\n");
       val='E';
   }
   else if (rc == 0)  /* select timed out */
   {
       printf("DEFAULT path\n");
       val='D';
   }
   else 
   {
      if (FD_ISSET(0, &fdset)) 
      {
         val = getchar();
      }
   }
   printf("VAL is %c\n", val);
}