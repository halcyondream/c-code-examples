#include "main.h"
#include <stdlib.h>

// Run the simulation.
int main() {
  hospital_t *hospital = (hospital_t *)malloc(sizeof(hospital_t));
  if (hospital == NULL) {
    exitWithError("Malloc failed to allocate memory for hospital.");
  }
  initializeHospital(hospital, 100);
  while (hospital->stats->totalRecovered != hospital->totalRooms) {
    clearStatistics(hospital->stats);
    dailyHospitalUpdates(hospital);
    printHospitalStats(hospital);
  }
  deinitHospital(hospital);
  free(hospital);
  hospital = NULL;
  return 0;
}

// Run updates on the hospital and patients for a single day.
void dailyHospitalUpdates(hospital_t *hospital) {
  patient_t *patient = hospital->patients;
  while (patient != hospital->patients + hospital->totalRooms) {
    updatePatientState(patient);
    updateStatsFromStage(hospital->stats, patient->stage);
    patient++;
  }
}

// Increment statistics based on a given stage (ie from a patient).
void updateStatsFromStage(stats_t *stats, stage_t stage) {
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