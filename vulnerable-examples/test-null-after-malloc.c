#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main() {

  // malloc will return NULL if it fails to allocate memory. Test that
  // an instance is not NULL after trying to allocate memory. Do not
  // assume that malloc has succeeded until then.
  float *vector;
  int allocSize;
  
  allocSize = 20 * sizeof(float);
  vector = (float *)malloc(allocSize);
  if (vector == NULL) {
    // Malloc has failed.
    return -1;
  }
  // Else, malloc has succeeded.
  *vector = 1.0;
  free(vector);

  //
  // Use an inappropriately large allocation size. This causes malloc
  // to yield an error.
  //
  allocSize = UINT64_MAX;
  vector = (float *)malloc(allocSize);
  //
  // In this case, the code is vulnerable because malloc will return
  // NULL, along with a nasty warning about the allocSize. Attempting
  // to modify the value of vector will result in undefined behavior.
  //
  // As earlier, there should be a check to ensure whether vector is
  // NULL after allocation. If so, there was an error with allocation,
  // and the application should terminate gracefully. Because no such
  // check exists, the application will segfault.
  //
  *vector = 1.0; 
  printf("Value of float: %f\n", *vector);
}