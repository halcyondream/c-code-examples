#include "patient.h"
#include "errors.h"
#include <stdlib.h>

// Helper function for patients.
static gender_t getRandomGender() {
  int result = rand() % 2;
  if (result) {
    return GENDER_MALE;
  }
  return GENDER_FEMALE;
}

void initializePatient(patient_t *patient) {
  patient->stage = getRandomStage();
  patient->daysLeft = 3;
  patient->gender = getRandomGender();
  patient->gettingWorse = true;
}

void updatePatientTimer(patient_t *patient) {
  if (patient->daysLeft > 3) {
    exit(error_code_INVALID_DAYS_LEFT);
  }
  if (patient->daysLeft) {
    (patient->daysLeft)--;
  }
}
