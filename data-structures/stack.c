#include "stack.h"
#include <stdlib.h>

Stack *newStack() { return newLinkedList(); }

void freeStack(Stack *stack) { freeLinkedList(stack); }

void push(Stack *stack, void *data) { prepend(stack, data); }

void *pop(Stack *stack) {
  Node *node = stack->head;

  // If the list is empty, return nil.
  if (!stack->head) {
    return NULL;
  }

  // If you pop the only element in the list, set the list elements to nil.
  if (stack->head == stack->tail) {
    stack->head = stack->tail = NULL;

    // Search for the second-to-last item in the list. Make it the new tail.
  } else {
    stack->head = stack->head->next;
  }

  // Free the node and return its data.
  void *data = node->data;
  free(node);
  return data;
}