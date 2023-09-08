// p169-170

typedef struct _employee {
  char name[10];
  int age;
} Employee;

typedef struct _item {
  int partNumber;
  int quantity;
  int binNumber;
} Item;

int main() {
  Employee employee;
  char *ptr = employee.name;
  ptr += sizeof(
      employee.name); // Note: Boundary/offset size not guaranteed in structure.
                      // Even if it were, struct ptr arithmetic is bad practice.

  Item part = {12345, 35, 107};

  // Bad example: This won't necessarily cycle between structure
  // properties. Recall that they are not necessarily
  // contiguous in memory (unlike arrays).
  int *pi = &part.partNumber;
  printf("Part number: %d\n", *pi);
  pi++;
  printf("Quantity: %d\n", *pi);
  pi++;
  printf("Bin number: %d\n", *pi);

  // Less bad example: If absolutely necessary, assign a pointer to
  // each needed property.
  pi = &part.partNumber;
  // printf...
  pi = &part.quantity;
  // printf...
  pi = &part.binNumber;
  // printf...

  // Or, better yet: DONT USE POINTERS.
  // printf part.number, directly
  //...
}