//Stack ADT for multiple Data Types

// Node of a tree (Include Guard to Handle recursive Inclusion)
#ifndef BST_H
#define BST_H
#include"bst.h"
#endif

// Node of tree as data of Queue
typedef node* sinfi;

// For Large Data
typedef long long INT;

// Node of Stack 
typedef struct nodeS{
    sinfi data;
    struct nodeS* next;
}nodeS;

// Node pointer as a stack
typedef nodeS* stack;

// Functions on Stack
void initStack(stack *S1);
void push(stack *S1,sinfi data);
sinfi pop(stack *S1);
int isEmptyStack(stack S1);
sinfi stackTop(stack S1);