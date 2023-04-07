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

Customer customerCreate(int id, int items) {
    Customer cr;
    cr.id = id;
    cr.items = items;
    return cr;
}

int main(void)
{
    return 0;
}