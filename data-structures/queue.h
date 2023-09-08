#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"

typedef LinkedList Queue;

Queue *newQueue();
void freeQueue(Queue *queue);
void enqueue(Queue *queue, void *node);
void *dequeue(Queue *queue);

#endif