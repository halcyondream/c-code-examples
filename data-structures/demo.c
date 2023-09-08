#include "demo.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create three sample employees.
  Employee *jane = employeeConstructor("Jane Doe", 33);
  Employee *bill = employeeConstructor("Bill Please", 21);
  Employee *burt = employeeConstructor("Burt Fickin' Reynolds", 47);

  // Display the different data structures' behaviors.
  demoLinkedList(jane, bill, burt);
  demoQueue(jane, bill, burt);
  demoStack(jane, bill, burt);
  demoTree(jane, bill, burt);

  // Remove the employees.
  employeeDestructor(jane);
  employeeDestructor(bill);
  employeeDestructor(burt);
}

void demoLinkedList(Employee *e1, Employee *e2, Employee *e3) {
  printf("\n--Starting Linked List demo--\n");

  LinkedList *list = newLinkedList();

  prepend(list, e1);
  prepend(list, e2);
  prepend(list, e3);
  printf("\nAfter prepend: ");
  displayLinkedList(list, DISPLAY);

  deleteAllLinkedListNodes(list);

  append(list, e1);
  append(list, e2);
  append(list, e3);
  printf("\nAfter append: ");
  displayLinkedList(list, DISPLAY);

  Node *deleteThisNode = getLinkedListNode(list, COMPARE, e1);
  deleteLinkedListNode(list, deleteThisNode);
  printf("\nAfter deleting %s: ", e1->name);
  displayLinkedList(list, DISPLAY);

  printf("\nDestroying list...\n");
  freeLinkedList(list);
}

void demoQueue(Employee *e1, Employee *e2, Employee *e3) {
  printf("\n--Starting Queue demo--\n");

  Queue *queue = newQueue();

  enqueue(queue, e1);
  enqueue(queue, e2);
  enqueue(queue, e3);
  displayLinkedList(queue, DISPLAY);

  void *data = (Employee *)dequeue(queue);
  printf("Dequeued %s\n", ((Employee *)data)->name);

  Employee *data2 = dequeue(queue);
  printf("Dequeued %s\n", data2->name);

  freeLinkedList(queue);
}

void demoStack(Employee *e1, Employee *e2, Employee *e3) {
  printf("\n--Starting Stack demo--\n");

  Stack *stack = newStack();

  push(stack, e1);
  push(stack, e2);
  push(stack, e3);
  displayLinkedList(stack, DISPLAY);

  Employee *employee;

  while (1) {
    employee = (Employee *)pop(stack);

    if (!employee) {
      break;
    }

    printf("Popped %s\n", employee->name);
  }

  freeStack(stack);
}

void demoTree(Employee *e1, Employee *e2, Employee *e3) {
  printf("\n--Starting Tree demo--\n");

  Employee *e4 = employeeConstructor("Hulla Balloo", 33);
  Employee *e5 = employeeConstructor("Porcupine Tree", 21);
  Employee *e6 = employeeConstructor("Some Other", 47);

  TreeNode *tree = newTree();

  insertNode(&tree, compareEmployee, e1);
  insertNode(&tree, compareEmployee, e2);
  insertNode(&tree, compareEmployee, e3);
  insertNode(&tree, compareEmployee, e4);
  insertNode(&tree, compareEmployee, e5);
  insertNode(&tree, compareEmployee, e6);

  printf("\nIn-order traversal: ");
  visitInOrder(tree, displayEmployee);

  printf("\nPre-order traversal: ");
  visitPreOrder(tree, displayEmployee);

  printf("\nPost-order traversal: ");
  visitPostOrder(tree, displayEmployee);

  freeTree(&tree);

  employeeDestructor(e4);
  employeeDestructor(e5);
  employeeDestructor(e6);
}
