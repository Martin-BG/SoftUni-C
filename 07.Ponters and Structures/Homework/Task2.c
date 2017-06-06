/*Task 2:
Make a program that consist of single structure that is
called "Student". The struct must have the following
properties - Name, Height, Weight, Grade, Average mark.
The program must be able to save information for 10
students (the information is generated randomly with the
required limits in the program) and to have a single
function that is calculating the average mark of all
10 students.
The program should be able to easily adjust the
number of imputed numbers by #define in the top.*/

#define STUDENTS 10
#define MAX_NAME_LEN 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char Name[MAX_NAME_LEN];
    unsigned int Height;
    unsigned int Weight;
    unsigned int Grade;
    float AverageMark;
} Student;

Student generateRandomStudent();
void printStudentInfo(Student);
float calcAverageMarkOfStudents(Student []);

int main(void)
{
    srand(time(NULL));

    Student students[STUDENTS];

    int index;
    for (index = 0; index < STUDENTS; index++)
    {
        students[index] = generateRandomStudent();
        printStudentInfo(students[index]);
    }

    printf ("\nAverage mark of all students: %.2f\n", calcAverageMarkOfStudents(students));

    return 0;
}

Student generateRandomStudent()
{
    static int counter = 0;

    Student student;
    sprintf(student.Name, "Student%d", counter + 1);
    student.Height = 120 + rand() % 60;
    student.Weight = 40 + rand() % 40;
    student.Grade = 1 + rand() % 12;
    student.AverageMark = 2.0f + 0.01f * (rand() % 400);

    counter++;

    return student;
}

void printStudentInfo(Student student)
{
    printf("Name: %s\nHeight: %u\nWeight: %u\nGrade: %u\nAverage mark: %.2f\n\n",
           student.Name, student.Height, student.Weight, student.Grade, student.AverageMark);
}

float calcAverageMarkOfStudents(Student students[STUDENTS])
{
    float averageMark = 0.0f;

    int index;

    for (index = 0; index < STUDENTS; index++)
    {
        averageMark += students[index].AverageMark;
    }

    averageMark /= STUDENTS;

    return averageMark;
}
