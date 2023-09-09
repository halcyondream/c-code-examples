#include "virus.h"

void tryWorsenPatient(patient_t *patient) {
  stage_t result = tryWorsenStage(patient->stage);
  if (result != patient->stage) {
    patient->stage = result;
    patient->daysLeft = 3;
    return;
  }
  patient->gettingWorse = false;
}

void tryImprovePatient(patient_t *patient) {
  patient->stage = tryImproveStage(patient->stage);
  if (patient->stage == STAGE_RECOVERED) {
    patient->gender = GENDER_NIL;
  }
}