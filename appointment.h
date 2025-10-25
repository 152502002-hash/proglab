#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#define MAX_APPOINTMENTS 200

typedef struct {
    int id;
    int patientId;
    int doctorId;
    char date[20]; /* simple string like "2025-10-18" or "18-10-2025" */
    char time[10]; /* simple string like "10:30" */
} Appointment;

void addAppointment();
void listAppointments();

#endif
