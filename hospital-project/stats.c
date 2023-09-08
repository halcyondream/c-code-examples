#include "stats.h"

// Reset statistics to zero for the new day. Caveat: This approach will
// not allow you to track daily changes/deltas.
void clearStatistics(stats_t *stats) {
  stats->totalGreens = 0;
  stats->totalYellows = 0;
  stats->totalReds = 0;
  stats->totalPurples = 0;
  stats->totalRecovered = 0;
}
