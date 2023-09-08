#include <stdio.h>

int main() {
  int num = 2147483647;
  int *pi = &num;
  short *ps = (short *)&pi;

  //
  // Results:
  //
  //   Int ptr:   0x16db7b5bc, Base 16: 7fffffff, Base 10:  2147483647
  //   Short ptr: 0x16db7b5b0, Base 16: ffffb5bc, Base 10: -19012
  //
  // This didn't really work out like the example. In the book, a short
  // is only one word, two bytes (ffff == -1). Here, it's a doubleword,
  // four bytes. The only similarity is that the short cast will treat
  // it as a negative value.
  //
  // A takeaway here is against the dangers of assuming that a cast
  // will correctly use the target data type. Suppose a function accepts
  // a short pointer. You can pass `(short*)&intPointer` to such a
  // function. However, as illustrated here, the behavior will be
  // undefined.
  //
  printf("Int ptr:   %p, Base 16: %x, Base 10: %d\n", pi, *pi, *pi);
  printf("Short ptr: %p, Base 16: %x, Base 10: %d\n", ps, *ps, *ps);
}