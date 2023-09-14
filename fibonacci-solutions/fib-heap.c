//
// Reworking of this solution. Uses dynamically-allocated memory to hold the numbers:
//
// https://docs.google.com/file/d/0BwtP9e5j1RbpSjhvSG4wbkhGcmM/edit?resourcekey=0-4JkyQslzn9gco3-VCPeW-A
//
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

//
// Try MAX:     20000000000000          malloc fails after this.
// UINT64_MAX:  18446724073709551615    Much larger than MAX. Fails malloc.
//
const long long unsigned int MAX = 1000000;

int main() {
  
  if (sizeof(uint8_t) * MAX < MAX) {
    printf("Error setting the composite number. Possible overflow.\n");
    exit(1);
  }
  
  printf("Allocating memory...\n");

  uint8_t *A = (uint8_t *)calloc(MAX, sizeof(uint8_t));
  uint8_t *B = (uint8_t *)calloc(MAX, sizeof(uint8_t));
  uint8_t *F_n = (uint8_t *)calloc(MAX, sizeof(uint8_t));
  
  if (!A || !B || !F_n) {
    printf("Error allocating memory.\n");
    exit(1);
  }
  
  printf("Done allocating memory.\n");
  printf("MX:  %llu\nBS:  %llu\n", MAX, sizeof(uint8_t)*MAX);
  printf("A:   %llu\nB:   %llu\nF_n: %llu\n", 
    MAX/sizeof(A[0]),
    MAX/sizeof(B[0]),
    MAX/sizeof(F_n[0])
  );

  long long unsigned int i;

  long long unsigned int ct1;
  long long unsigned int ct2;
  long long unsigned int ct3;
  long long unsigned int ct;

  int t1;

  int x;
  int y;

  size_t counter = 0;
  size_t maxcounter = MAX;

  A[MAX - 1] = '1';
  B[MAX - 1] = '1';

  ct1 = MAX - 2;
  ct2 = MAX - 2;
  ct3 = MAX - 1;

  printf("Starting...\n");

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

    // All digits in len( f(n) ) are occupied.
    if (F_n[0] != 0) { 
      break;
    }

    // Copy B -> A
    for (i = ct2 + 1; i < MAX; i++) {
      A[i] = B[i];
    }

    // Copy F(n) -> B
    for (i = ct3 + 1; i < MAX; i++) {
      B[i] = F_n[i];
    }
    counter++;
  }

#ifdef DEBUG

  // Print F(n).
  printf("Fibonacci number %lu: ", counter + 2);
  for (i = ct3 + 1; i < MAX; i++) {
    printf("%c", F_n[i]); // Remember the +'0' -> char integer!
    if (i > ct3 + 15) {
      break;
    }
  }
  printf("...%c\n\n", F_n[MAX - 1]);

  // Display utilization statistics.
  long long unsigned int a = 0;
  long long unsigned int b = 0;
  long long unsigned int c = 0;
  while (A[a++] == 0)
    ;
  while (B[b++] == 0)
    ;
  while (F_n[c++] == 0)
    ;
  printf("Utilized|Free space:\n");
  printf("A: %llu|%llu\nB: %llu|%llu\nC: %llu|%llu\n", MAX - a, a, MAX - b, b,
         MAX - c, b);
  printf("\n");

#endif

  return 0;
}