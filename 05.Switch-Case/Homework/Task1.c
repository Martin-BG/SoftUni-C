/*The C Programing basics lecturer needs help in the examination process. The
exam consists of test that has maximum of 30 points and 5 tasks with
maximum of 10 points each. There are also 10 points from homework and 10
points from homework evaluation. The data is inputed in the format "$test,
$task1, $task2, $task3, $task4, $task5, $homework",
$hw_evaluation" (everything is float).
Calculate the mark of the student, based on the sum if it's point :
0 - 44 = 2 (Poor)
45 - 59 = 3 (Average)
60 - 74 = 4 (Good)
75 - 79 = 5 (Very good)
80 + = 6 (Excellent).
Print a message with the alias of the mark*/

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

float calcFinalMark(float[]);
Result getStudentResult(const float);
void printStudentResult(Result);
void printMarkName(int mark);

int main(void)
{
    float marks[MARKS_NUM_OF];

    int i;
    for (i = 0; i < MARKS_NUM_OF; i++)
    {
        printf("Enter mark for ");
        printMarkName(i);
        printf(": ");
        scanf("%f", &marks[i]);
    }

    printf("\nFinal Mark = %.2f\n", calcFinalMark(marks));

    printStudentResult(getStudentResult(calcFinalMark(marks)));

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
