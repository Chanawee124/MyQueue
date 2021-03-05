//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2564 BE.
//

#ifndef Node_h
#define Node_h

struct node
{
    int data;
    struct node *nextPtr;
};
typedef struct node Node;
typedef struct node* NodePtr;

typedef struct  order
{
    int order_number; //หมายเลขออร์เดอร์
    int q;// จำนวน 
    struct order *O_nextPtr;
} Order;
typedef Order* OrderPtr;

#endif
