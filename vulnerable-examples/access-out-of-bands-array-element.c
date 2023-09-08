// p.164: Nothing can prevent a C program from accessing memory outside
// of the space allocated for an array.

#include <stdio.h>

int main() {
  char firstname[8] = "1234567";
  char middlename[8] = "1234567";
  char lastname[8] = "1234567";

  middlename[-2] = 'X'; // lastname[n-1]
  middlename[0] = 'X';  // middlename[0]
  middlename[10] = 'X'; // firstname[2]

  //
  // 0x16fdff600 12X4567   - firstname
  // 0x16fdff5f8 X234567   - middlename
  // 0x16fdff5f0 123456X   - lastname
  //
  // This checks out because the array "grows down".
  // middlename-2 is in a lower area of the stack, where lastname is
  // defined. middlename+10 goes to a higher area of the stack, where
  // firstname is defined.
  //

  printf("%p %s\n", firstname, firstname);
  printf("%p %s\n", middlename, middlename);
  printf("%p %s\n", lastname, lastname);
}