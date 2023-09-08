#ifndef STAGE
#define STAGE
#include <stdint.h>

typedef enum {
  STAGE_GREEN = 'G',
  STAGE_YELLOW = 'Y',
  STAGE_RED = 'R',
  STAGE_PURPLE = 'P',
  STAGE_RECOVERED = '.',
} stage_t;

stage_t tryWorsenStage(stage_t stage);
stage_t tryImproveStage(stage_t stage);
stage_t getRandomStage();
uint8_t _getRandomProbability();

#endif