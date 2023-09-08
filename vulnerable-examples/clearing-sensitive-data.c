#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *SECURITY_QUESTION_STRING = "LET ME BE FRANK WITH YOU";

int main() {
  char name[32];
  int userID;
  char *securityQuestion;

  // Assign values.
  strcpy(name, "Frank");
  securityQuestion = (char *)malloc(strlen(SECURITY_QUESTION_STRING) + 1);
  strcpy(securityQuestion, SECURITY_QUESTION_STRING);

  // Delete sensitive information.
  memset(name, 0, sizeof(name));
  userID = 0;
  memset(securityQuestion, 0, strlen(securityQuestion));

  printf("Name: %s\n", name);
  printf("Security quesstion: %s\n", securityQuestion);
}