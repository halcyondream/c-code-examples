#ifndef DATA_H
#define DATA_H
#include "interfaces.h"
#define DISPLAY (fptrDisplay) displayEmployee
#define COMPARE (fptrCompare) compareEmployee

typedef struct _employee {
  char name[32];
  unsigned char age;
} Employee;

int compareEmployee(Employee *e1, Employee *e2);
void displayEmployee(Employee *employee);
Employee *employeeConstructor(const char *name, unsigned char age);
void employeeDestructor(Employee *employee);

#endif
