#include <stdio.h>
#include <string.h>
#include "appointment.h"
#include "patient.h"
#include "doctor.h"

static Appointment appointments[MAX_APPOINTMENTS];
static int appointmentCount = 0;
static int nextAppointmentId = 1;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }

    int pid, did;
    printf("Enter patient ID: ");
    scanf("%d", &pid);
    while (getchar() != '\n');
    Patient *p = findPatientById(pid);
    if (!p) {
        printf("No patient found with ID %d\n", pid);
        return;
    }

    printf("Enter doctor ID: ");
    scanf("%d", &did);
    while (getchar() != '\n');
    Doctor *d = findDoctorById(did);
    if (!d) {
        printf("No doctor found with ID %d\n", did);
        return;
    }

    Appointment a;
    a.id = nextAppointmentId++;
    a.patientId = pid;
    a.doctorId = did;

    printf("Enter date (e.g. 2025-10-18): ");
    fgets(a.date, sizeof(a.date), stdin);
    if (a.date[strlen(a.date)-1] == '\n') a.date[strlen(a.date)-1] = '\0';

    printf("Enter time (e.g. 10:30): ");
    fgets(a.time, sizeof(a.time), stdin);
    if (a.time[strlen(a.time)-1] == '\n') a.time[strlen(a.time)-1] = '\0';

    appointments[appointmentCount++] = a;
    printf("Appointment added with ID: %d\n", a.id);
}

void listAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < appointmentCount; ++i) {
        Appointment *a = &appointments[i];
        Patient *p = findPatientById(a->patientId);
        Doctor  *d = findDoctorById(a->doctorId);
        printf("App ID: %d | Patient: %s (ID %d) | Doctor: %s (ID %d) | Date: %s | Time: %s\n",
            a->id,
            (p ? p->name : "Unknown"),
            a->patientId,
            (d ? d->name : "Unknown"),
            a->doctorId,
            a->date,
            a->time);
    }
}
