/*Use the functions from task 1 and make a program that is used for
inputing the data for 10 students and calculation their average mark.
It must be printed with the alias AND the numeric value.*/

#include<stdio.h>

typedef enum {
    Test = 0,
    Task1,
    Task2,
    Task3,
    Task4,
    Task5,
    Homework,
    Hw_evaluation,
    MARKS_NUM_OF
} Marks;

typedef enum {
    Poor = 2,
    Average,
    Good,
    Very_good,
    Excellent,
    RESULT_NUM_OF
} Result;

#define STUDENTS 10

float calcFinalMark(float[]);
Result getStudentResult(const float);
void printStudentResult(Result);
void printMarkName(int mark);

int main(void)
{
    float marks[MARKS_NUM_OF];
    float average_mark = 0.0f;

    int i, j;
    for (j = 0; j < STUDENTS; j++)
    {
        for (i = 0; i < MARKS_NUM_OF; i++)
        {
            printf("[Student %d] Enter mark for ", j + 1);
            printMarkName(i);
            printf(": ");
            scanf("%f", &marks[i]);
        }
        printf("\n");
        average_mark += calcFinalMark(marks);
    }

    average_mark /= STUDENTS;

    printf("\nAverage Mark for all students = %.2f\n\n", average_mark);

    printStudentResult(getStudentResult(average_mark));

    return 0;
}

void printMarkName(int mark)
{
    switch (mark)
    {
        case 0:
            printf("test");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("task%d", mark);
            break;
        case 6:
            printf("homework");
            break;
        case 7:
            printf("hw_evaluation");
            break;
        default:
            break;
    }
}

float calcFinalMark(float marks[])
{
    float final_mark = 0;

    int i;
    for (i = 0; i < MARKS_NUM_OF; i++)
    {
        final_mark += marks[i];
    }
    return final_mark;
}

Result getStudentResult(const float mark)
{
    if (mark < 45.0f)
    {
        return Poor;
    }
    else if (mark < 60.0f)
    {
        return Average;
    }
    else if (mark < 75.0f)
    {
        return Good;
    }
    else if (mark < 80.0f)
    {
        return Very_good;
    }

    return Excellent;
}

void printStudentResult(Result result)
{
    switch(result)
    {
        case Poor:
            printf("2 (Poor)\n");
            break;
        case Average:
            printf("3 (Average)\n");
            break;
        case Good:
            printf("4 (Good)\n");
            break;
        case Very_good:
            printf("5 (Very good)\n");
            break;
        case Excellent:
            printf("6 (Excellent)\n");
            break;
        default:
            printf("Error - invalid result\n");
            break;
    }
}
