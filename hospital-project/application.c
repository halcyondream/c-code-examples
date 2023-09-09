#include "application.h"
#include "errors.h"
#include "visitor.h"
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
    visitPatient(patient);
    updateStatsFromStage(hospital->stats, patient->stage);
    patient++;
  }
}
