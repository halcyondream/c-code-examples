// p168 references strcat_s and strcpy_s, both of which are available only
// for windows. The strn* functions are available in GCC. Note that in
// either case, you still have to set the correct size, otherwise you can
// cause undefined behavior.
#include <stdio.h>

int main(int argc, char **argv) {
  // Note: This will print arbitrary data to stdout. No formatting.
  // Note: Will throw an exception.
  printf(argv[1]);
}