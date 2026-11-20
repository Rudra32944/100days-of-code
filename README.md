# Student Record and Result Management System

## Project Information

- **Program:** B.Tech CSE
- **Course:** Programming in C
- **Course Code:** PRC1001
- **Student:** Rudra Gupta
- **SAP ID:** 590032944
- **Batch:** 19
- **Language:** C

## Project Title

**AI-Assisted Student Record and Result Management System**

## Project Description

This is a console-based, menu-driven Student Record and Result Management System developed in C. It stores and manages student academic details and provides operations such as adding, searching, displaying, deleting, sorting, and calculating CGPA. Student records are saved in a binary file so that the data can be loaded again when the program is restarted.

The project also contains a simple AI-Assisted Academic Advisor. The advisor does not connect to an AI API. It uses CGPA-based categories and `if-else` logic to provide academic advice.

## Student Information Stored

For each student, the program stores:

- SAP ID
- Roll Number
- Name
- Phone Number
- Email ID
- Year (1-4)
- Current Semester (1-8)
- SGPA values for completed semesters
- CGPA

## Features

1. Add a new student record.
2. Display all student records.
3. Display records in increasing order of SAP ID.
4. Display records in increasing order of student name.
5. Search for a student using SAP ID.
6. Delete an individual student record.
7. Calculate the CGPA of each student using available SGPA values.
8. Calculate the average CGPA of students belonging to each year.
9. Provide CGPA-based academic advice using the AI-Assisted Academic Advisor.
10. Save student records to `Students.dat` and load them when the program starts.

## CGPA Calculation

The CGPA is calculated as the average of the SGPA values available up to the student's current semester:

`CGPA = Sum of available SGPA values / Number of completed semesters`

## AI-Assisted Academic Advisor

The advisor classifies students according to CGPA and displays a recommendation:

| CGPA | Category | Advice |
|---|---|---|
| 8.5 and above | Excellent Performance | Maintain the current study pattern and explore advanced learning opportunities. |
| 7.0 to below 8.5 | Good Performance | Keep up the good work and focus on improving weaker subjects. |
| 5.0 to below 7.0 | Needs Improvement | Focus more on subjects with lower SGPA and follow a regular study schedule. |
| Below 5.0 | Requires Immediate Attention | Give immediate attention to weak subjects and seek guidance from faculty. |

## Files in the Repository

```text
student-record-ai-c/
├── 590032944.c
├── README.md
├── AI_USAGE_LOG.md
└── tests/
    ├── sample_input.txt
    └── sample_output.txt
```

`Students.dat` is created by the program while saving student records.

## How to Compile and Run

Using GCC:

```bash
gcc 590032944.c -o student_record
./student_record
```

On Windows, you can run the generated executable after compilation:

```bash
gcc 590032944.c -o student_record.exe
student_record.exe
```

## Main Menu

```text
1. Add Student
2. Display all Student
3. Display in Increasing order of SAP Id
4. Display in Increasing order of Name
5. Search and Display record of Student
6. Delete a student Record
7. Calculation of CGPA of student till his current Semester
8. Calculation of Average CGPA of all year student
9. AI-Assisted Academic Advisor
10. Exit
```

## Concepts Used

- Structures
- Functions
- Arrays
- Pointers
- Dynamic memory allocation (`malloc` and `realloc`)
- File handling
- Loops
- Conditional statements
- String handling
- Searching
- Bubble sort
- Menu-driven programming

## AI Usage

ChatGPT was used only as a learning assistant for understanding concepts, designing simple academic-advisor logic, reviewing ideas, and improving documentation. AI suggestions were checked and adapted before being used in the project. Details are recorded in `AI_USAGE_LOG.md`.

## Author

**Rudra Gupta**  
**SAP ID: 590032944**
