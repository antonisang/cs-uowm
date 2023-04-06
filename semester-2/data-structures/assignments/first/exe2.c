#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
WARNING: Reducing the array size might break
things; Consider adjusting the "breaker" variable
and the for range in the "main" function for more
customization options.
*/
#define ARRAY_SIZE 50

typedef struct {
    unsigned short int AEM;
    float Grade;
} Student;


bool IsPrime(int num) 
{
    int i, x;
    if (num < 2) return false;
    x = num / 2;
    for (i = 2; i < x; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

float FindGrade(Student stds[], int AEM)
{
    int middle, counter=1, left=0, right=ARRAY_SIZE-1;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        printf("Search %d student AEM: %d\n", counter, stds[middle].AEM);
        
        if (stds[middle].AEM == AEM) return stds[middle].Grade;
        if (stds[middle].AEM < AEM) left = middle + 1;
        if (stds[middle].AEM > AEM) right = middle - 1;
        counter++;
    }
}

int CountBiggerGrade(Student stds[], float grade)
{
    int counter = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Search %d student AEM: %d\n", i + 1, stds[i].AEM);
        if (stds[i].Grade > grade) counter++;
    }
    return counter;
}

int main(void) 
{
    // Change this value to your actual student ID
    srand(1111);
    int i, breaker=0, target;
    float target_grade;
    Student students[ARRAY_SIZE];

    for (i = 2000; i <= 2400; i++)
    {
        if (IsPrime(i)) {
            students[breaker].AEM = i;
            students[breaker].Grade = (rand() % 101)/10;
            breaker++;
        }
        if (breaker == ARRAY_SIZE) break;
    }

    printf("Enter student AEM: ");
    scanf("%d", &target);

    target_grade = FindGrade(students, target);

    printf("\nGrade of student %d is %.1f\n\n", target, target_grade);
    printf("\nThe number of students with bigger grade than %d is %d", target, CountBiggerGrade(students, target_grade));
    return 0;
}
