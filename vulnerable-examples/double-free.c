// p172
#include <stdlib.h>

int main() {
  char *name = (char *)malloc(12);
  free(name);
  // free(name); // This will cause an exception.
  //  Also, NULL or zero the freed pointer to prevent use-after-free.
  name = NULL;

  // Note that double-free can also occur with pointers to an already-
  // freed object, like:
  name = (char *)malloc(12);
  char *name2 = name;
  free(name);
  // free(name2);  // Exception.
  name = NULL;
  name2 = NULL;
}