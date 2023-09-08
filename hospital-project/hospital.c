#include "hospital.h"
#include "errors.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Initialize a hospital instance. TODO: Fix the potential memory leak.
void initializeHospital(hospital_t *hospital, uint8_t totalRooms) {
  hospital->totalRooms = totalRooms;
  hospital->patients = (patient_t *)malloc(sizeof(patient_t) * totalRooms);
  if (hospital->patients == NULL) {
    exitWithError("malloc failed to create patient array.");
  }
  hospital->stats = (stats_t *)malloc(sizeof(stats_t));
  if (hospital->stats == NULL) {
    exitWithError("malloc failed to create statistics buffer.");
  }
  patient_t *patient = hospital->patients;
  while (patient != hospital->patients + hospital->totalRooms) {
    patient->stage = getRandomStage();
    patient->daysLeft = 3;
    patient->gender = getRandomGender();
    patient->gettingWorse = true;
    patient++;
  }
  clearStatistics(hospital->stats);
}

// Deallocate and NULLify the nested structures in the hospital.
void deinitHospital(hospital_t *hospital) {
  free(hospital->patients);
  hospital->patients = NULL;
  free(hospital->stats);
  hospital->stats = NULL;
}

// Print the current room and hospital statistics.
void printHospitalStats(const hospital_t *hospital) {
  static uint64_t day = 0;
  patient_t *patient = hospital->patients;
  uint8_t rowCounter = 0;
  if (day == UINT64_MAX) {
    exitWithError("Simulation exceeded acceptable number of days.");
  }
  printf("Day %llu:\n", ++day);
  while (patient != hospital->patients + hospital->totalRooms) {
    printf("[%c%c] ", patient->stage, patient->gender);
    if (++rowCounter % 10 == 0) {
      printf("\n");
    }
    patient++;
  }
  printf("\n");
}