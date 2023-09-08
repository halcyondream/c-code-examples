// p160.

#define PINT int *

typedef int *pint_t;

int main() {

  // Bad examples. Only ptr1 is an int ptr. But ptr2 is an int. It looks
  // misleading when you read it.
  int *ptr1, ptr2;
  PINT ptr1, ptr2;

  // Good examples.
  int *ptr1, *ptr2;
  pint_t ptr1, ptr2;
}