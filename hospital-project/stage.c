#include "stage.h"
#include <stdlib.h>

// Helper function for stage-changing behaviors.
uint8_t _getRandomProbability() { return rand() % 100; }

// Helper function for stages.
stage_t getRandomStage() {
  uint8_t stageNumber = rand() % 4;
  switch (stageNumber) {
  case 0:
    return STAGE_GREEN;
  case 1:
    return STAGE_YELLOW;
  case 2:
    return STAGE_RED;
  case 3:
    return STAGE_PURPLE;
  default:
    return STAGE_RECOVERED;
  }
}

// Try to demote a stage. If the stage is PURPLE, don't process
// anything.
stage_t tryWorsenStage(stage_t stage) {
  uint8_t worsens;
  if (stage == STAGE_PURPLE) {
    return stage;
  }
  worsens = _getRandomProbability();
  if (stage == STAGE_GREEN && worsens > 50) {
    return STAGE_YELLOW;
  }
  if (stage == STAGE_YELLOW && worsens > 40) {
    return STAGE_RED;
  }
  if (stage == STAGE_RED && worsens > 20) {
    return STAGE_PURPLE;
  }
  return stage;
}

// Try to promote a stage. If the stage is RECOVERED, don't process
// anything.
stage_t tryImproveStage(stage_t stage) {
  uint8_t improves;
  if (stage == STAGE_RECOVERED) {
    return stage;
  }
  improves = _getRandomProbability();
  if (stage == STAGE_PURPLE && improves > 30) {
    return STAGE_RED;
  }
  if (stage == STAGE_RED && improves > 40) {
    return STAGE_YELLOW;
  }
  if (stage == STAGE_YELLOW && improves > 60) {
    return STAGE_GREEN;
  }
  if (stage == STAGE_GREEN && improves > 75) {
    return STAGE_RECOVERED;
  }
  return stage;
}
