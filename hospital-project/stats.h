#ifndef STATS
#define STATS
#include <stdint.h>

typedef struct stats_s {
  uint8_t totalGreens;
  uint8_t totalYellows;
  uint8_t totalReds;
  uint8_t totalPurples;
  uint8_t totalRecovered;
} stats_t;

void clearStatistics(stats_t *stats);

#endif