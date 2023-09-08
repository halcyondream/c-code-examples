#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace(char buffer[], char replacement, size_t size) {
  size_t count = 0;
  while (*buffer != NULL && count++ < size) {
    *buffer = replacement;
    buffer++;
  }
}

// Note: Strcpy fails to overwrite, throws a compiler/runtime error.
int main() {
  char name[8]; // Declare 'name' as 8 characters.
  strcpy(
      name,
      "Alexander"); // Note: strcpy will write all 9 characters, past buffer==8.
  replace(name, '+',
          sizeof(name)); // replace will respect/validate the name size.
  printf("%s\n", name);  //
}