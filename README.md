# Hospital Patient Record System (C)

A menu-driven **Hospital Patient Record System** written in C using structured programming concepts.

**Course:** CSE1202 – Structured Programming Lab  
**Institution:** University of Liberal Arts Bangladesh (ULAB)  
**Student:** Khadijatul Kubra Evana (ID: 243014101)  
**Section:** 04 | **Semester:** Spring 2025

---

## Features

1. **Add New Patient** – Enter name, age, diagnosis & treatment (auto-assigns unique ID)
2. **Update Patient Details** – Modify diagnosis and treatment of an existing patient
3. **Remove Patient Record** – Delete a patient by ID
4. **Search Patient by ID** – Find and display full details of a patient
5. **Display All Patient Records** – Show all records in a clean table
6. **Exit** – Close the program gracefully

---

## How to Compile & Run

### Using GCC (Linux / macOS / Windows with MinGW)

```bash
gcc patient_record.c -o patient_record
./patient_record
```

### Using Code::Blocks or any IDE
1. Create a new C project / file
2. Copy the content of `patient_record.c`
3. Build and Run

---

## Concepts Used

- Structures (`struct Patient`)
- Arrays of structures
- Functions (modular design)
- String handling (`fgets`, `strcspn`, `strcpy` style)
- Loops & Conditionals
- Menu-driven interface with `switch-case`
- Basic input validation & error messages

---

## Data Structure

```c
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char diagnosis[MAX_DIAGNOSIS_LENGTH];
    char treatment[MAX_TREATMENT_LENGTH];
} Patient;
```

Maximum capacity: **100 patients** (stored in memory).

---

## Sample Menu

```
=== Hospital Patient Record System ===
1. Add New Patient
2. Update Patient Details
3. Remove Patient Record
4. Search Patient by ID
5. Display All Patient Records
0. Exit
Enter your choice:
```

---

## Future Improvements

- File-based data persistence (save/load records)
- Stronger input validation
- Search by name
- Sort records
- Graphical / web interface

---

## License

This project was created as an academic assignment. Feel free to use it for learning purposes.
