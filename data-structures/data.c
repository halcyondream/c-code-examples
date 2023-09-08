#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareEmployee(Employee *e1, Employee *e2) {
  return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee *employee) {
  printf(" [%s|%d] ", employee->name, employee->age);
}

Employee *employeeConstructor(const char *name, unsigned char age) {
  Employee *employee = (Employee *)malloc(sizeof(Employee));
  strcpy(employee->name, name);
  employee->age = age;
  return employee;
}

void employeeDestructor(Employee *employee) {
  free(employee);
  employee = NULL;
}