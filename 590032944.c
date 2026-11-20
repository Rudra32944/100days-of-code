/*name RUDRA GUPTA
batch 19 
sap id 590032944
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FILE_NAME "Students.dat"
struct Student {
    int SAP_ID;
    long long int Roll_No;
    char name[60];
    long long int Phone_No;
    char Email_Id[45];
    int Year;
    int Semester;          // current semester (1-8)
    float SGPA[8];         // SGPA of semester 1..8
    float CGPA;
};

struct Student *s = NULL;
int count = 0, capacity = 0;

int findIndex(int sap);
float calcCGPA(int i);


void saveToFile() {
	FILE *fp = fopen(FILE_NAME,"wb");
	if(fp == NULL) {
		printf("Warning:could not save to file.\n");
		return;
	}
	int recSize = (int) sizeof(struct Student);
	fwrite(&recSize, sizeof(int), 1, fp);
	fwrite(&count,sizeof(int),1,fp);
	if(count>0)
		fwrite(s,sizeof(struct Student),count,fp);
	fclose(fp);
}
void loadFromFile() {
	FILE *fp =fopen(FILE_NAME,"rb");
	if(fp==NULL)
		return;
	
	int recSize =0,n=0;
	if(fread(&recSize,sizeof(int),1,fp) !=1 || recSize != (int)sizeof(struct Student)) {
		printf("Saved file has a different format,so it was ignored.\n");
		fclose(fp);
		return;
	}
	if (fread(&n, sizeof(int), 1, fp) != 1 || n <= 0) {
		fclose(fp);
		return;
	}
	s =malloc(n* sizeof(struct Student));
	if(s==NULL) {
		printf("Memory Aloocation Failed!\n");
		fclose(fp);
		return;
	}
	capacity =n;
	count = (int)fread(s,sizeof(struct Student),n,fp);
	fclose(fp);
	printf("Loaded %d record(s) from %s.\n",count,FILE_NAME);
}

void AcademicAdvisor(struct Student *p)
{
    printf("\n========== AI-ASSISTED ACADEMIC ADVISOR ==========\n");
    printf("Student: %s\n", p->name);
    printf("CGPA: %.2f\n", p->CGPA);

    if (p->CGPA >= 8.5)
    {
        printf("Category: Excellent Performance\n");
        printf("Advice: Maintain your current study pattern and explore advanced learning opportunities.\n");
    }
    else if (p->CGPA >= 7.0)
    {
        printf("Category: Good Performance\n");
        printf("Advice: Keep up the good work and focus on improving weaker subjects.\n");
    }
    else if (p->CGPA >= 5.0)
    {
        printf("Category: Needs Improvement\n");
        printf("Advice: Focus more on subjects with lower SGPA and follow a regular study schedule.\n");
    }
    else
    {
        printf("Category: Requires Immediate Attention\n");
        printf("Advice: Give immediate attention to weak subjects and seek guidance from faculty.\n");
    }
}

void AcademicAdvisorBySAP()
{
    int sap;

    printf("\nEnter SAP ID for Academic Advice: ");
    scanf("%d", &sap);

    int index = findIndex(sap);

    if (index == -1)
    {
        printf("Student not found.\n");
        return;
    }

    s[index].CGPA = calcCGPA(index);
    AcademicAdvisor(&s[index]);
}



int findIndex(int sap) {
    for (int i = 0; i < count; i++)
        if (s[i].SAP_ID == sap) return i;
    return -1;
}


float calcCGPA(int i) {
    float total = 0;
    for (int j = 0; j < s[i].Semester; j++)
        total += s[i].SGPA[j];
    return total / s[i].Semester;
}

void printStudent(struct Student *p) {
    printf("SAP ID: %d\n", p->SAP_ID);
    printf("Roll no.: %lld\n", p->Roll_No);
    printf("Name: %s\n", p->name);
    printf("Phone no.: %lld\n", p->Phone_No);
    printf("Email Id: %s\n", p->Email_Id);
    printf("Year: %d\n", p->Year);
    printf("Current Semester: %d\n", p->Semester);
    for (int j = 1; j <= p->Semester; j++)
        printf("SGPA of Semester %d: %.2f\n", j, p->SGPA[j - 1]);
    printf("CGPA: %.2f\n", p->CGPA);
}



void addStudent() {
    char choice;

    do {
        if (count == capacity) {
            int newCap = (capacity == 0) ? 2 : capacity * 2;
            struct Student *temp = realloc(s, newCap * sizeof(struct Student));
            if (temp == NULL) {
                printf("--------error--------\n");
                return;                     // old data is still valid in s
            }
            s = temp;
            capacity = newCap;
        }

        printf("\nStudent %d\n", count + 1);

        printf("SAP ID:");
        scanf("%d", &s[count].SAP_ID);
        if (findIndex(s[count].SAP_ID) != -1) {
            printf("A student with this SAP ID already exists.\n");
        } else {
            printf("Roll no.:");
            scanf("%lld", &s[count].Roll_No);
            printf("Name:");
            scanf(" %59[^\n]", s[count].name);
            printf("Phone no.:");
            scanf("%lld", &s[count].Phone_No);
            printf("Email Id:");
            scanf("%44s", s[count].Email_Id);

            do {
                printf("Year (1-4):");
                scanf("%d", &s[count].Year);
            } while (s[count].Year < 1 || s[count].Year > 4);

            do {
                printf("Current Semester (1-8):");
                scanf("%d", &s[count].Semester);
            } while (s[count].Semester < 1 || s[count].Semester > 8);

            for (int i = 1; i <= s[count].Semester; i++) {
                printf("SGPA of Semester %d:", i);
                scanf("%f", &s[count].SGPA[i - 1]);
            }

            s[count].CGPA = calcCGPA(count);
            count++;
            saveToFile();
	  }

        printf("Add another student?(Y/N):");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');
}



void SearchAndDisplay() {
    int r, found;
    char again;

    do {
        found = 0;
        printf("\nEnter the SAP ID to search:");
        scanf("%d", &r);

        for (int i = 0; i < count; i++) {
            if (s[i].SAP_ID == r) {
                printf("\n-------Student Found with SAP ID %d-------\n", r);
                printStudent(&s[i]);
                found = 1;
                break;
            }
        }
        if (found == 0)
            printf("Student with the given SAP Id not found.\n");

        printf("\nDo You Want to search Another Student?(y/n):");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');
}



void CGPA() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        s[i].CGPA = calcCGPA(i);
        printf("CGPA till Semester %d of Student with SAP ID %d is:%.2f\n",
               s[i].Semester, s[i].SAP_ID, s[i].CGPA);
    }
}



void DisplayAllRecords() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printStudent(&s[i]);
    }
}



void deleteStudent() {
    int r;
    printf("Enter the SAP ID:");
    scanf("%d", &r);

    int k = findIndex(r);               // -1 means not found
    if (k == -1)
        printf("Student not found.\n");
    else {
        for (int j = k; j < count - 1; j++)
            s[j] = s[j + 1];
        count--;
		saveToFile();
        printf("Record deleted.\n");
    }
}



void DisplayAscendingNumber() {
    struct Student temp;

    if (count == 0) {
        printf("No record found.\n");
        return;
    }

    struct Student *t = malloc(count * sizeof(struct Student));
    if (t == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    for (int i = 0; i < count; i++)
        t[i] = s[i];

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
            if (t[j].SAP_ID > t[j + 1].SAP_ID) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }

    printf("\n--------Records in increasing order of SAP ID--------\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printStudent(&t[i]);
    }
    free(t);
}



void DisplayAscendingName() {
    struct Student temp;

    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    struct Student *t = malloc(count * sizeof(struct Student));
    if (t == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    for (int i = 0; i < count; i++)
        t[i] = s[i];

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (strcmp(t[j].name, t[j + 1].name) > 0) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }

    printf("\n--------Records in increasing order of Name--------\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printStudent(&t[i]);
    }
    free(t);
}



void CGPAavg() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 1; i <= 4; i++) {
        float total = 0;
        int q = 0;
        for (int j = 0; j < count; j++) {
            if (s[j].Year == i) {
                total += s[j].CGPA;
                q++;
            }
        }
        if (q == 0)
            printf("Year %d: no students.\n", i);
        else
            printf("The Average CGPA of %d Year Students:%.2f\n", i, total / q);
    }
}

int main() {
    int choice;
loadFromFile();
    do {
        printf("\n========STUDENT RECORD & MANAGEMENT SYSTEM========\n");
        printf("1. Add Student\n");
        printf("2. display all Student\n");
        printf("3. Display in Increasing order of SAP Id\n");
        printf("4.Display in Increasing order of Name\n");
        printf("5. Search and Display record of Student\n");
        printf("6.Delete a student Record\n");
        printf("7.Calculation of CGPA of student till his current Semester\n");
        printf("8.Calculation of Average CGPA of all year student\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("10. Exit\n");

        printf("Enter your choice:");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n') { }
            choice = 0;
        }
        switch (choice) {
            case 1: addStudent(); break;
            case 2: DisplayAllRecords(); break;
            case 3: DisplayAscendingNumber(); break;
            case 4: DisplayAscendingName(); break;
            case 5: SearchAndDisplay(); break;
            case 6: deleteStudent(); break;
            case 7: CGPA(); break;
            case 8: CGPAavg(); break;
			case 9: AcademicAdvisorBySAP();break;
            case 10: printf("Exiting.....\nHave Wonderful day ahead"); break;
			
            default: printf("Invalid Choice! Try again.\n");
        }
    } while (choice != 10);

    free(s);
    return 0;
}
	

	