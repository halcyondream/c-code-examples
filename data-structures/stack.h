#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"

typedef LinkedList Stack;

Stack *newStack();
void freeStack(Stack *stack);
void push(Stack *stack, void *data);
void *pop(Stack *stack);

#endif