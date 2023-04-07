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
    int frontIndex;
    int rearIndex;
    int itemsCount;
} CashDesk;

Customer customerCreate(int id, int items) {
    Customer cr;
    cr.id = id;
    cr.items = items;
    return cr;
}

CashDesk *cashDesksInit(void) {
    int i, j;
    static CashDesk cashDesks[NO_OF_CASH_DESKS];
    for (i = 0; i < NO_OF_CASH_DESKS; i++)
    {
        for (j = 0; j < MAX_QUEUE_SIZE; j++)
        {
            cashDesks[i].customers[j] = customerCreate(j, j);
        }
        cashDesks[i].frontIndex = 0;
        cashDesks[i].rearIndex = 0;
        cashDesks[i].itemsCount = 0;
    }
    return cashDesks;
}

bool cashDeskIsEmpty(CashDesk cd) {
    return cd.frontIndex == 0;
}

bool cashDeskIsFull(CashDesk cd) {
    return cd.rearIndex == MAX_QUEUE_SIZE - 1;
}



int main(void)
{
    CashDesk *cashDesks = cashDesksInit();
    
    return 0;
}