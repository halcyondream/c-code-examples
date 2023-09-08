// https://docs.google.com/file/d/0BwtP9e5j1RbpSjhvSG4wbkhGcmM/edit?resourcekey=0-4JkyQslzn9gco3-VCPeW-A

#include <stdint.h>
#include <stdio.h>
#define DEBUG
#define MAX 100000

int main() {

  unsigned char A[MAX] = {};
  unsigned char B[MAX] = {};
  // Fibonacci(n): The nth number of the fibonacci sequence.
  unsigned char F_n[MAX] = {};

  int i;

  int ct1;
  int ct2;
  int ct3;
  int ct;

  int t1;

  int x;
  int y;

  int counter = 0;
  int maxcounter = MAX;

  A[MAX - 1] = '1';
  B[MAX - 1] = '1';

  ct1 = MAX - 2;
  ct2 = MAX - 2;
  ct3 = MAX - 1;

  while (counter < maxcounter - 2) {

    if (ct1 > ct2) { // ct is the larger of the B first digits.
      ct = ct1;
    } else {
      ct = ct2;
    } // End setting ct

    i = MAX - 1;
    x = 0;
    y = 0;

    while (i > ct || x > 0 || y > 0) {

      if (A[i] == 0) {
        ct1--;
        A[i] = '0';
      }

      if (B[i] == 0) {
        ct2--;
        B[i] = '0';
      }

      if (y == 1) {

        if (x == 1) {
          y = 1;
        } else {
          x = 1;
          y = 0;
        }
      }

      t1 = (A[i] - '0') + (B[i] - '0') + x; // Add F_n digits to t1, t1 < 20
      x = 0;

      if (F_n[i] == 0) {
        ct3--;
      }

      if (t1 <= 9) { // If 0-9 (digit), prepend to f(n)
        F_n[i] = t1 + '0';

      } else {

        t1 = t1 % 10; // Get the "rollover" digit
        F_n[i] = t1 + '0';

        if ((A[i - 1] + 1) > '9') {
          x = 0;
          y = 1;

        } else {
          x = 1;
        }
      }

      i--;
    }

    if (F_n[0] != 0) { // All digits in len( f(n) ) are occupied.
      break;
    }

    for (i = ct2 + 1; i < MAX; i++) { // Copy B -> A
      A[i] = B[i];
    }

    for (i = ct3 + 1; i < MAX; i++) {
      B[i] = F_n[i];
    } // Copy F(n) -> B
    counter++;
  }

#ifdef DEBUG

  // Print F(n).
  printf("Fibonacci number %d: ", counter + 2);
  for (i = ct3 + 1; i < MAX; i++) {
    printf("%c", F_n[i]); // Remember the +'0' -> char integer!
    if (i > ct3 + 15) {
      break;
    }
  }
  printf("...%c\n\n", F_n[MAX - 1]);

  // Display utilization statistics.
  int a = 0;
  int b = 0;
  int c = 0;
  while (A[a++] == 0)
    ;
  while (B[b++] == 0)
    ;
  while (F_n[c++] == 0)
    ;
  printf("Utilized|Free space:\n");
  printf("A: %d|%d\nB: %d|%d\nC: %d|%d\n", MAX - a, a, MAX - b, b, MAX - c, b);
  printf("\n");

#endif

  return 0;
}