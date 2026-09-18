#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DIAGNOSIS_LENGTH 100
#define MAX_TREATMENT_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char diagnosis[MAX_DIAGNOSIS_LENGTH];
    char treatment[MAX_TREATMENT_LENGTH];
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;
int nextId = 1;

/* Remove trailing newline from fgets input */
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

/* Display the main menu */
void displayMenu() {
    printf("\n=== Hospital Patient Record System ===\n");
    printf("1. Add New Patient\n");
    printf("2. Update Patient Details\n");
    printf("3. Remove Patient Record\n");
    printf("4. Search Patient by ID\n");
    printf("5. Display All Patient Records\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

/* Add a new patient */
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Error: Maximum patient capacity reached.\n");
        return;
    }

    Patient newPatient;
    newPatient.id = nextId++;

    printf("\nEnter patient details:\n");

    printf("Name: ");
    getchar();  /* clear leftover newline from previous input */
    fgets(newPatient.name, MAX_NAME_LENGTH, stdin);
    removeNewline(newPatient.name);

    printf("Age: ");
    scanf("%d", &newPatient.age);
    getchar();  /* clear newline after age */

    printf("Diagnosis: ");
    fgets(newPatient.diagnosis, MAX_DIAGNOSIS_LENGTH, stdin);
    removeNewline(newPatient.diagnosis);

    printf("Treatment Plan: ");
    fgets(newPatient.treatment, MAX_TREATMENT_LENGTH, stdin);
    removeNewline(newPatient.treatment);

    patients[patientCount++] = newPatient;
    printf("Patient added successfully with ID: %d\n", newPatient.id);
}

/* Update diagnosis and treatment of an existing patient */
void updatePatient() {
    int id;
    printf("\nEnter patient ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\nCurrent Details:\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Diagnosis: %s\n", patients[i].diagnosis);
            printf("Treatment: %s\n", patients[i].treatment);

            printf("\nEnter new diagnosis: ");
            fgets(patients[i].diagnosis, MAX_DIAGNOSIS_LENGTH, stdin);
            removeNewline(patients[i].diagnosis);

            printf("Enter new treatment plan: ");
            fgets(patients[i].treatment, MAX_TREATMENT_LENGTH, stdin);
            removeNewline(patients[i].treatment);

            printf("Patient record updated successfully.\n");
            return;
        }
    }
    printf("Error: Patient with ID %d not found.\n", id);
}

/* Remove a patient record by ID */
void removePatient() {
    int id;
    printf("\nEnter patient ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient record removed successfully.\n");
            return;
        }
    }
    printf("Error: Patient with ID %d not found.\n", id);
}

/* Search and display a patient by ID */
void searchPatient() {
    int id;
    printf("\nEnter patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\nPatient Details:\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Diagnosis: %s\n", patients[i].diagnosis);
            printf("Treatment: %s\n", patients[i].treatment);
            return;
        }
    }
    printf("Error: Patient with ID %d not found.\n", id);
}

/* Display all patient records in a table */
void displayAllPatients() {
    if (patientCount == 0) {
        printf("\nNo patient records available.\n");
        return;
    }

    printf("\n=== All Patient Records ===\n");
    printf("ID\tName\t\tAge\tDiagnosis\t\tTreatment\n");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%d\t%s\t%d\t%s\t%s\n",
               patients[i].id,
               patients[i].name,
               patients[i].age,
               patients[i].diagnosis,
               patients[i].treatment);
    }
}

int main() {
    int choice;

    printf("=== Hospital Patient Record System ===\n");
    printf("Initializing system...\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient();          break;
            case 2: updatePatient();       break;
            case 3: removePatient();       break;
            case 4: searchPatient();       break;
            case 5: displayAllPatients();  break;
            case 0: printf("Exiting system...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
