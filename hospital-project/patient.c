#include "patient.h"
#include <stdlib.h>

// Update the patient for the current day.
void updatePatientState(patient_t *patient) {
  stage_t result;
  if (patient->stage == STAGE_RECOVERED) {
    return;
  }
  if (patient->daysLeft) {
    (patient->daysLeft)--;
  }
  if (patient->daysLeft && patient->stage == STAGE_PURPLE) {
    return;
  }
  if (patient->gettingWorse) {
    result = tryWorsenStage(patient->stage);
    if (result != patient->stage) {
      patient->stage = result;
      patient->daysLeft = 3;
      return;
    }
    patient->gettingWorse = false;
  }
  patient->stage = tryImproveStage(patient->stage);
  if (patient->stage == STAGE_RECOVERED) {
    patient->gender = GENDER_NIL;
  }
}

// Helper function for patients.
gender_t getRandomGender() {
  int result = rand() % 2;
  if (result) {
    return GENDER_MALE;
  }
  return GENDER_FEMALE;
}