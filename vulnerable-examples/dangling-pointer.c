#include <stdlib.h>

int main() {

  int *list = (int *)malloc(10 * sizeof(int));

  // The dangling pointer occurs when the list is freed, but then
  // re-used. This causes a read against arbitrary memory data.
  // You can prove that it's still pointing to said memory
  // location; not gonna actually print data wherever, but you
  // could if you really wanted.
  free(list);
  printf("%x\n", list);

  // Better use-case: set the free'd pointer to null.
  list = NULL;
  printf("%d\n", list);
}