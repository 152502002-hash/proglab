#include <stdio.h>
#include <string.h>
#include "doctor.h"

static Doctor doctors[MAX_DOCTORS];
static int doctorCount = 0;
static int nextDoctorId = 1;

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor list is full.\n");
        return;
    }

    Doctor d;
    d.id = nextDoctorId++;
    printf("Enter doctor name: ");
    fgets(d.name, sizeof(d.name), stdin);
    if (d.name[strlen(d.name)-1] == '\n') d.name[strlen(d.name)-1] = '\0';
    printf("Enter specialty: ");
    fgets(d.specialty, sizeof(d.specialty), stdin);
    if (d.specialty[strlen(d.specialty)-1] == '\n') d.specialty[strlen(d.specialty)-1] = '\0';

    doctors[doctorCount++] = d;
    printf("Doctor added with ID: %d\n", d.id);
}

void listDoctors() {
    if (doctorCount == 0) {
        printf("No doctors added yet.\n");
        return;
    }
    printf("Doctors:\n");
    for (int i = 0; i < doctorCount; ++i) {
        printf("ID: %d | Name: %s | Specialty: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].specialty);
    }
}

Doctor* findDoctorById(int id) {
    for (int i = 0; i < doctorCount; ++i)
        if (doctors[i].id == id)
            return &doctors[i];
    return NULL;
}
