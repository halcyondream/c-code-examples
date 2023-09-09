#ifndef PATIENT
#define PATIENT
#include "stage.h"
#include <stdbool.h>
#include <stdint.h>

typedef enum {
  GENDER_MALE = 'M',
  GENDER_FEMALE = 'F',
  GENDER_NIL = '.'
} gender_t;

typedef struct patient_s {
  stage_t stage;
  gender_t gender;
  uint8_t daysLeft;
  bool gettingWorse;
} patient_t;

void initializePatient(patient_t *patient);
void tryImprovePatient(patient_t *patient);
void tryWorsenPatient(patient_t *patient);
void updatePatientTimer(patient_t *patient);

#endif