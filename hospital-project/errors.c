#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

void exitWithError(char *message) {
  printf("ERROR: %s\nExiting.\n", message);
  exit(-1);
}