// p 161

#define NULL 0

int main() {
  // Bad example. Prints uninitialized/arbitrary data.
  int *pi;
  printf("%d\n", pi);

  // Ways to deal with these:
  // - Initialize with NULL
  // - assert ptr != NULL
  // - Third-party tools.
  //
  // example using null.
  int *pi = NULL;
  if (pi != NULL) {
    printf("%d\n, pi");
  }
}