#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
} Patient;

/* patient functions */
void addPatient();
void listPatients();
Patient* findPatientById(int id);

#endif
