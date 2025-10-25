#ifndef DOCTOR_H
#define DOCTOR_H

#define MAX_DOCTORS 50

typedef struct {
    int id;
    char name[50];
    char specialty[50];
} Doctor;

/* doctor functions */
void addDoctor();
void listDoctors();
Doctor* findDoctorById(int id);

#endif
