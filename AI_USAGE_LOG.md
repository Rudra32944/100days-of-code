# AI Usage Log

## Project

**AI-Assisted Student Record and Result Management System**

**Student:** Rudra Gupta  
**SAP ID:** 590032944  
**AI Tool Used:** ChatGPT

## Purpose of AI Use

ChatGPT was used as a learning assistant during the project. The suggestions were reviewed and adapted to the requirements of the C program rather than being used blindly. The final program uses normal C functions, conditions, loops, structures, file handling, and other concepts studied in the course.

## AI Usage Entries

| AI Tool | Prompt / Question Asked | How I Used / Verified the Response |
|---|---|---|
| ChatGPT | Suggest simple CGPA-based academic advice categories that can be implemented in C using `if-else` statements. | I used the idea to create four categories: Excellent Performance, Good Performance, Needs Improvement, and Requires Immediate Attention. I converted the idea into C `if-else` logic and checked that the CGPA ranges do not overlap. |
| ChatGPT | Give test cases for a CGPA-based academic advisor, including high, medium, and low CGPA values. | I manually tested CGPA values from different ranges and checked whether the program displayed the expected category and advice. |
| ChatGPT | Explain how to calculate a student's CGPA by taking the average of the available SGPA values. | I used the explanation to understand the required logic. I verified it manually by adding the SGPA values and dividing by the number of completed semesters. |
| ChatGPT | Explain how a student record can be searched using SAP ID in a C program. | I used the explanation to understand linear search. I checked the search with both an existing SAP ID and a SAP ID that was not present. |
| ChatGPT | Help me prepare a README and AI usage log for my C Student Record and Result Management System GitHub repository. | I compared the documentation with my actual program and assignment requirements and kept only the features implemented in the project. |

## Verification of the AI-Assisted Advisor

The academic-advisor logic used in the program was checked with cases from different CGPA ranges.

| Example CGPA | Expected Category |
|---|---|
| 9.00 | Excellent Performance |
| 7.50 | Good Performance |
| 6.20 | Needs Improvement |
| 4.50 | Requires Immediate Attention |

The boundary conditions were also considered:

- CGPA >= 8.5: Excellent Performance
- CGPA >= 7.0 and < 8.5: Good Performance
- CGPA >= 5.0 and < 7.0: Needs Improvement
- CGPA < 5.0: Requires Immediate Attention

## What I Learned from AI Assistance

Using ChatGPT helped me understand how a general suggestion can be converted into programming logic. I learned to:

- break a requirement into smaller functions;
- convert CGPA ranges into `if-else` conditions;
- think of test cases before accepting a solution;
- verify calculations manually;
- improve project documentation;
- use AI as a learning assistant rather than blindly copying its output.

## Important Note

The AI-assisted feature in this project does **not** connect the C program to ChatGPT or any external AI API. The final academic recommendation is generated locally by the C program using predefined CGPA ranges and `if-else` statements.
