#include <stdio.h>
#include <string.h>
#include "patient.h"

static Patient patients[MAX_PATIENTS];
static int patientCount = 0;
static int nextPatientId = 1;

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full.\n");
        return;
    }

    Patient p;
    p.id = nextPatientId++;
    printf("Enter patient name: ");
    // read line without leaving newline
    fgets(p.name, sizeof(p.name), stdin);
    if (p.name[strlen(p.name)-1] == '\n') p.name[strlen(p.name)-1] = '\0';
    printf("Enter patient age: ");
    scanf("%d", &p.age);
    while (getchar() != '\n'); // clear input buffer

    patients[patientCount++] = p;
    printf("Patient added with ID: %d\n", p.id);
}

void listPatients() {
    if (patientCount == 0) {
        printf("No patients added yet.\n");
        return;
    }
    printf("Patients:\n");
    for (int i = 0; i < patientCount; ++i) {
        printf("ID: %d | Name: %s | Age: %d\n",
               patients[i].id, patients[i].name, patients[i].age);
    }
}

Patient* findPatientById(int id) {
    for (int i = 0; i < patientCount; ++i)
        if (patients[i].id == id)
            return &patients[i];
    return NULL;
}
