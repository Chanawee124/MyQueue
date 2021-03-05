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

int dequeue(Queue *Q){
  int value;
  OrderPtr t;

  if(Q->size>0){
    t = Q->headPtr;
    value = t->order_number;
    
    //if(Q->headPtr==Q->tailPtr) Q->tailPtr=NULL;
    
    Q->headPtr = t->O_nextPtr;
    if(Q->size == 1) Q->tailPtr = NULL;
    //if( Q->headPtr==NULL)  Q->tailPtr=NULL;
    Q->size--;
    
    free(t);
    return value;
  }

  return 0;

}

void show_all(Queue *Q)
{
  Queue *ptr = Q;
  while(ptr->headPtr->O_nextPtr != NULL){
    printf("My Order is %d\n",ptr->headPtr->order_number);
    ptr->headPtr = ptr->headPtr->O_nextPtr;
  }
}