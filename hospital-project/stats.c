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

// Increment statistics based on a given stage (ie from a patient).
void updateStatsFromStage(stats_t *stats, const stage_t stage) {
  switch (stage) {
  case STAGE_GREEN:
    stats->totalGreens++;
    break;
  case STAGE_YELLOW:
    stats->totalYellows++;
    break;
  case STAGE_RED:
    stats->totalReds++;
    break;
  case STAGE_PURPLE:
    stats->totalPurples++;
    break;
  case STAGE_RECOVERED:
    stats->totalRecovered++;
    break;
  }
}