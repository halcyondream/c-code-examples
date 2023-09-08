#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList *newLinkedList() {
  LinkedList *new = (LinkedList *)malloc(sizeof(LinkedList));
  _initialize(new);
  return new;
}

// Deletes all nodes and frees the provided list.
void freeLinkedList(LinkedList *list) {
  Node *traverse = list->head;

  for (Node *remove = traverse; remove != NULL; remove = traverse) {
    traverse = remove->next;
    free(remove);
  }

  free(list);
}

static void _initialize(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

void prepend(LinkedList *list, void *data) {
  Node *node = (Node *)malloc(sizeof(Node));

  node->data = data;

  // Empty head.
  if (list->head == NULL) {
    list->tail = node;
    node->next = NULL;

    // Otherwise, bump the current head to the second placement.
  } else {
    node->next = list->head;
  }

  // Make the target node the new head.
  list->head = node;
}

void append(LinkedList *list, void *data) {

  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  // If the list is empty, this is both head and tail.
  if (list->head == NULL) {
    list->head = node;

    // Otherwise, append to the current tail.
  } else {
    list->tail->next = node;
  }

  // Set as tail unconditionally.
  list->tail = node;
}

Node *getLinkedListNode(LinkedList *list, fptrCompare compare, void *data) {

  Node *node = list->head;

  // Loop until the data is found in the list.
  while (node) {

    if (compare(node->data, data) == 0) {
      return node;
    }
    node = node->next;
  }

  // If data is not in the list, return nil.
  return NULL;
}

void deleteLinkedListNode(LinkedList *list, Node *node) {

  // Corner case: the node is the head element.
  if (node == list->head) {

    // Corner case: The node is the only element in the list. Set
    // the head and tail pointers to nil.
    if (list->head->next == NULL) {
      list->head = NULL;
      list->tail = NULL;

      // Otherwise, implicitly remove the node by setting the head to
      // the next list element.
    } else {
      list->head = list->head->next;
    }

    // Otherwise, the node is any other element in the list.
  } else {

    Node *tmp = list->head;

    // Stops when the target node is found.
    while (tmp && tmp->next != node) {
      tmp = tmp->next;
    }

    // If the target node is found, tmp will have a value. Set its
    // next node to that of the target's next node. Implicitly
    // removes it from the list.
    if (tmp) {
      tmp->next = node->next;
    }
  }

  // Regardless of all outcomes, free the target node's heap memory.
  free(node);
}

// Delete all nodes. Since order doesn't matter after deletion, there's
// no need to call the deleteLinkedListNode function. By the way, this solution
// is almost verbatim from the SEI CERT-C Standards (2016), p.257.
void deleteAllLinkedListNodes(LinkedList *list) {
  Node *traverse = list->head;

  // Set the head, tail nodes to nil.
  _initialize(list);

  // My original solution was a `while` list that basically did what
  // you'd expect.
  for (Node *remove = traverse; remove != NULL; remove = traverse) {
    traverse = remove->next;
    free(remove);
  }
}

void displayLinkedList(LinkedList *list, fptrDisplay display) {
  Node *current = list->head;

  printf("\nLinked nodes: ");

  while (current) {
    display(current->data);
    current = current->next;
  }

  printf("\n");
}
