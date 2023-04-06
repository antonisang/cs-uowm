#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Modify this value to adjust stack size.
WARNING: Stack size of 5 supports AEM values up to
9999
*/
#define STACK_SIZE 5

typedef struct {
    int Array[STACK_SIZE];
    size_t Index;
} StaticStack;

// Initialize the stack by filling it with zeros
void StaticStack_Init(StaticStack *stack) 
{
    size_t i;
    for (i = 0; i < STACK_SIZE; i++) {
        stack -> Array[i] = 0;
    }  
    stack -> Index = 0;
}

// Push an int item to the stack, returns true on a successful push and false on a fail
bool StaticStack_Push(StaticStack *stack, int item)
{
    if (stack -> Index < STACK_SIZE) {
        stack -> Array[stack->Index] = item;
        stack -> Index++;
        return true;
    }
    return false;
}

// Check whether the content of the passed stack is palindrome or not 
bool StaticStack_IsPalindrome(StaticStack *stack)
{
    int bottom = 0, top = stack -> Index - 1;
    if (stack -> Index == 1) return true;
    if (stack -> Index == 2) return (stack -> Array[0] == stack -> Array[1]);
    while (bottom != top) {
        if (stack -> Array[bottom] != stack -> Array[top]) return false;
        bottom++;
        top--;
    }
    return true;
    

}

/*
Push the remainder of a number when dividing by 8 to 
the stack and return the quotient of division with 8. 
Use this function recursively to obtain the octal 
form of a decimal number into a stack
*/
long OctalDigit(StaticStack *stack, int num) 
{
    if (StaticStack_Push(stack, num % 8)) {
        return num / 8;
    }
    printf("ERROR Stack overflow occured, shutting down...");
    exit(1);
}

int main(void) 
{
    int AEM, i;
    long temp;
    StaticStack ss;

    StaticStack_Init(&ss);

    // Change this value to your actual student ID
    AEM = 1111;
    
    temp = AEM;
    do {
        temp = OctalDigit(&ss, temp);
    } while (temp != 0);

    printf("\nOctal form of AEM is: ");
    for (i = STACK_SIZE; i > 0 ; i--) {
        printf("%d ", ss.Array[i-1]);
    }

    if (StaticStack_IsPalindrome(&ss)) {
        printf("\n\nOctal representation of %d IS palindrome", AEM);
    } else {
        printf("\n\nOctal representation of %d IS NOT palindrome", AEM);
    }
    
    return 0;
}