// p166
#include <stdio.h>

int main() {
  int buffer[20];
  int *pbuffer = buffer;

  // Incorrect sizeof usage here. sizeof(buffer) == 80, but there are
  // obviously only 20 elements in the buffer as declared earlier.
  // This will overwrite areas of memory.
  //
  // Print statement added as a courtesy for the impending runtime
  // exception.
  for (int i = 0; i < sizeof(buffer); i++) {
    *(pbuffer++) = 0;
    printf("%d\n", i);
  }
}