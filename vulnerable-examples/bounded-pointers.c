#include <stdio.h>

#define SIZE 32

int main() {
  char name[SIZE];
  char *p = name;

  //
  //   name: 6ef2f5a8, name+32: 6ef2f5c8, p: 6ef2f5a8
  //
  printf("name: %x, name+%d: %x, p: %x\n", name, SIZE, name + SIZE, p);

  //
  // This approach will work, but can get tedious.
  //
  // Alternatives:
  //
  // -    Create a pointer-validation function: https://bit.ly/ZeU1aO,
  //          https://wiki.sei.cmu.edu/confluence/display/c/MEM10-C.+Define+and+use+a+pointer+validation+function
  //
  // -    Use the Bounded Model Checking for ANSI-C and C++:
  // https://www.cprover.org/cbmc/
  //
  if (name) {

    if (p >= name && p < name + SIZE) {
      // valid pointer
    } else {
      // Invalid pointer: raise exception.
    }
  }
}