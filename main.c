#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

void q_left(Queue *Q);

int main(int argc , char **argv) {
   Queue Q;
   Q.headPtr=NULL;
   Q.tailPtr=NULL;
   Q.size=0;
  int i;
  int c = 1;

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
            show_all(&Q);
            printf("Customer no: %d\n",c); c++;
            dequeue(&Q);
        }
        else {
       enqueue(&Q, atoi(argv[i]),atoi(argv[i+1]));
            i++;
        }
}
    q_left(&Q);
return 0;
}

void q_left(Queue *Q){
  printf("==========================================\n");
  printf("There are %d people left in the queue\n",Q->size);
}