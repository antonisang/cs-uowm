#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
#define NO_OF_CUSTOMERS 60
#define NO_OF_CASH_DESKS 3

typedef struct {
    int id;
    int items;
} Customer;

typedef struct {
    Customer customers[MAX_QUEUE_SIZE];
    int fIndex;
    int rIndex;
    int old_size;
    int new_size;
} CashDesk;


int main(void)
{
    return 0;
}