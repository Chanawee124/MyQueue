#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

int main(int argc , char **argv) {
   Queue Q;
   Q.headPtr=NULL;
   Q.tailPtr=NULL;
   Q.size=0;
  int i,cost,cash;
   int c = 1;
/* for(i=1;i<argc;i++) 
         enqueue(&Q, atoi(argv[i]));
         
   while(Q.size>0)
        printf("%d\n",dequeue(&Q));*/

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
            show_all(&Q);
            //x=dequeue(&Q); // ผลคำนวน ราคา 
            //printf("My order is %d\n",x);
            printf("Customer no: %d\n",c); c++;
            switch(Q.headPtr->order_number){
              case 1 : printf("Ramen\n");
                       cost = 100*(Q.headPtr->q);
                       printf("You have to pay %d\n",cost);
                       break;
              case 2 : printf("Hotdog\n");
                       cost = 200*(Q.headPtr->q);
                       printf("You have to pay %d\n",cost);
                       break;
              case 3 : printf("Pizza\n");
                       cost = 300*(Q.headPtr->q);
                       printf("You have to pay %d\n",cost);
                       break;
            }
            do{
              scanf(":Cash: %d", &cash);
              if(cost < cash) printf("Thank you\nChange is: %d",cash-cost);
              else if(cost == cash) printf("Thank you\n");
              
            }while(cost > cash);
            printf("There are %d people int the queue",Q.size);
        }
        else {
       enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
            i++;
        }
        
  
}
return 0;
}