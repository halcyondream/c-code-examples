#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "interfaces.h"

typedef struct _node {
  void *data;
  struct _node *next;
} Node;

typedef struct _linked_list {
  Node *head;
  Node *tail;
} LinkedList;

LinkedList *newLinkedList();
void freeLinkedList(LinkedList *list);
void prepend(LinkedList *list, void *data);
void append(LinkedList *list, void *data);
Node *getLinkedListNode(LinkedList *list, fptrCompare compare, void *data);
void deleteLinkedListNode(LinkedList *list, Node *node);
void deleteAllLinkedListNodes(LinkedList *list);
void displayLinkedList(LinkedList *list, fptrDisplay display);
static void _initialize(LinkedList *list);

#endif