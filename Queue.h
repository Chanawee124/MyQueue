#include "Node.h"

typedef struct {
	OrderPtr headPtr,tailPtr;
	int size;
}Queue;

void enqueue(Queue *Q, int n1, int n2){
   
   OrderPtr new_node;

   new_node=(OrderPtr) malloc(sizeof(Order));
   if(new_node){
     new_node->order_number=n1;
     new_node->q=n2;
     new_node->O_nextPtr=NULL;
     if(Q->headPtr==NULL) 
        Q->headPtr=new_node;
     else   
        Q->tailPtr->O_nextPtr = new_node;
     Q->tailPtr = new_node;
     Q->size++;
   }

}

void dequeue(Queue *Q){
  int value,price,cash;
  OrderPtr t;
  
    
    if(Q->headPtr->order_number == 1){
      printf("Ramen\n");
      price = 100*(Q->headPtr->q);
      printf("You have to pay %d\n",price);
    }
    else if(Q->headPtr->order_number == 2){
      printf("Hotdog\n");
      price = 200*(Q->headPtr->q);
      printf("You have to pay %d\n",price);
    }
    else if(Q->headPtr->order_number == 3){
      printf("Pizza\n");
      price = 300*(Q->headPtr->q);
      printf("You have to pay %d\n",price);
    }
    
    if(Q->size>0){
    t = Q->headPtr;
    value = t->order_number;
    Q->headPtr = t->O_nextPtr;
    if(Q->size == 1) Q->tailPtr = NULL;
    Q->size--;
    free(t);
    }
    do{
      printf(":Cash: ");
      scanf("%d", &cash);
    }while(price > cash);

    if(price == cash) 
      printf("Thank you\n");
    else if(price < cash)
      printf("Thank you\nChange is: %d\n",cash-price);
    
    

}


void show_all(Queue *Q)
{
  OrderPtr ptr = Q->headPtr;

  while(ptr->O_nextPtr != NULL){
    printf("My Order is %d\n",ptr->order_number);
    ptr = ptr->O_nextPtr;
  }
  ptr = NULL;
}