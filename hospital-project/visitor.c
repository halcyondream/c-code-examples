#include "visitor.h"
#include "patient.h"
#include "stage.h"
#include "virus.h"

// Check to see if the patient's condition is worsening or improving.
void visitPatient(patient_t *patient) {
  stage_t previousStage;
  if (patient->stage == STAGE_RECOVERED) {
    return;
  }
  updatePatientTimer(patient);
  if (patient->daysLeft && patient->stage == STAGE_PURPLE) {
    return;
  }
  previousStage = patient->stage;
  if (patient->gettingWorse) {
    tryWorsenPatient(patient);
    if (patient->stage != previousStage) {
      return;
    }
  }
  tryImprovePatient(patient);
}
