#include <stdio.h>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"

void showMenu() {
    printf("\n=== Hospital Management ===\n");
    printf("1. Add patient\n");
    printf("2. List patients\n");
    printf("3. Add doctor\n");
    printf("4. List doctors\n");
    printf("5. Add appointment\n");
    printf("6. List appointments\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            // invalid input, clear buffer
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: addPatient(); break;
            case 2: listPatients(); break;
            case 3: addDoctor(); break;
            case 4: listDoctors(); break;
            case 5: addAppointment(); break;
            case 6: listAppointments(); break;
            case 0: printf("Goodbye!\n"); return 0;
            default: printf("Unknown option. Try again.\n");
        }
    }
    return 0;
}
