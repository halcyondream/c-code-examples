#ifndef ERRORS
#define ERRORS

typedef enum {
  error_code_INVALID_DAYS_LEFT
} error_code;

void exitWithError(char *message);

#endif