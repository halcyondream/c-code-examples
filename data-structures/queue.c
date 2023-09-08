#include "queue.h"
#include <stdlib.h>

Queue *newQueue() { return newLinkedList(); }

// Safely free the given `queue` and all elements.
void freeQueue(Queue *queue) { freeLinkedList(queue); }

void enqueue(Queue *queue, void *node) { append(queue, node); }

void *dequeue(Queue *queue) {
  Node *node = queue->head;

  if (!node) {
    return NULL;
  }

  if (node == queue->tail) {
    queue->head = queue->tail = NULL;

  } else {
    queue->head = queue->head->next;
  }

  void *data = node->data;
  free(node);
  return data;
}