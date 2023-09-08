#ifndef HOSPITAL
#define HOSPITAL
#include "patient.h"
#include "stage.h"
#include "stats.h"
#include <stdint.h>

void exitWithError(char *message);

typedef struct hospital_s {
  uint8_t totalRooms;
  patient_t *patients;
  stats_t *stats;
} hospital_t;

void initializeHospital(hospital_t *hospital, uint8_t totalRooms);
void deinitHospital(hospital_t *hospital);
void dailyHospitalUpdates(hospital_t *hospital);
void printHospitalStats(const hospital_t *hospital);
void updateStatsFromStage(stats_t *stats, stage_t stage);

#endif