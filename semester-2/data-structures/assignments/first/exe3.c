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
            cashDesks[i].customers[j] = customerCreate(0, 0);
        }
        cashDesks[i].frontIndex = -1;
        cashDesks[i].rearIndex = -1;
        cashDesks[i].itemsCount = 0;
    }
    return cashDesks;
}

bool cashDeskIsEmpty(CashDesk cd) {
    return cd.frontIndex == -1;
}

bool cashDeskIsFull(CashDesk cd) {
    return ((cd.frontIndex == cd.rearIndex + 1) || (cd.frontIndex == 0 && cd.rearIndex == MAX_QUEUE_SIZE -1));
}

void cashDeskAdd(CashDesk *cd, Customer cm) {
    if (!cashDeskIsFull(*cd)) {
        if (cd->frontIndex == -1) cd->frontIndex = 0;
        cd->rearIndex = (cd->rearIndex + 1) % MAX_QUEUE_SIZE;
        cd->customers[cd->rearIndex] = cm;
        cd->itemsCount++;
    }
};

void cashDeskRemove(CashDesk *cd) {
    if (!cashDeskIsEmpty(*cd)) {
        if (cd->frontIndex == cd->rearIndex)
        {
            cd->customers[cd->frontIndex] = customerCreate(0, 0);
            cd->frontIndex = -1;
            cd->rearIndex = -1;
            cd->itemsCount--;
        } else {
            cd->customers[cd->frontIndex] = customerCreate(0, 0);
            cd->frontIndex = (cd->frontIndex + 1) % MAX_QUEUE_SIZE;
            cd->itemsCount--;
        }
    }
}

bool _cashDesksAllFull(CashDesk cds[]) {
    int i;
    for (i = 0; i < NO_OF_CASH_DESKS; i++)
    {
        if (!cashDeskIsFull(cds[i])) return false;
    }
    return true;
}

bool _cashDesksAllEqual(CashDesk cds[]) {
    int i, temp = cds[0].itemsCount;
    for (i = 1; i < NO_OF_CASH_DESKS; i++)
    {
        if (cds[i].itemsCount != temp) return false;
    }
    return true;
}

bool cashDesksAllEmpty(CashDesk cds[]) {
    int i;
    for (i = 0; i < NO_OF_CASH_DESKS; i++)
    {
        if (cds[i].itemsCount != 0) return false;
    }
    return true;
}

int _cashDeskLessItems(CashDesk cds[]) {
    int i, cd=0, lowestItems = MAX_QUEUE_SIZE;
    for (i = 0; i < NO_OF_CASH_DESKS; i++)
    {
        if (cds[i].itemsCount < lowestItems) {
            lowestItems = cds[i].itemsCount;
            cd = i;
        };
    }
    return cd;
}

int cashDeskSelect(CashDesk cds[]) {
    int i, selectedDesk = -1, lowestQueueItems = MAX_QUEUE_SIZE + 5, check = cds[0].itemsCount;
    if (_cashDesksAllFull(cds)) return -1;
    if (_cashDesksAllEqual(cds)) return rand() % NO_OF_CASH_DESKS;
    return _cashDeskLessItems(cds);
}

int randomNumber(int max, int min) {
    int mx = max;
    if (min == 0) max++;
    return rand() % max + min;
};

void customersServe(CashDesk cds[]) {
    int i;
    for (i = 0; i < NO_OF_CASH_DESKS; i++)
    {
        if (cds[i].customers[cds[i].frontIndex].items <= 3) {
            cashDeskRemove(&cds[i]);
            printf("| %-4d%-6d%-6d|  ", 0, 0, cds[i].itemsCount);
            continue;
        };
        cds[i].customers[cds[i].frontIndex].items -= 3;
        printf("| %-4d%-6d%-6d|  ", cds[i].customers[cds[i].frontIndex].id, cds[i].customers[cds[i].frontIndex].items, cds[i].itemsCount);
    }
}

void printHeaders(void) {
    int i;
    printf("%20c", ' ');
    for (i = 0; i < NO_OF_CASH_DESKS; i++) printf(" |  Cash Desk - %d  | ", i);
    printf("\nRound  Dice  Action  ");
    for (i = 0; i < NO_OF_CASH_DESKS; i++) printf("| No  Cart  Total |  ");    
}

int main(void)
{
    int i, dice, selectedDesk, roundCount=1, customersCount=0;
    char action;
    Customer customer;
    CashDesk *cashDesks = cashDesksInit();

    printHeaders();

    srand(4470);
    do {
        dice = randomNumber(9, 1);
        action = dice > 2 ? '-' : '+';
        printf("\n%-7d%-6d%-7c ", roundCount, dice, action);
        if (dice < 3) {
            selectedDesk = cashDeskSelect(cashDesks);
            if (selectedDesk == -1) {
                for (i = 0; i < NO_OF_CASH_DESKS; i++)
                {
                    printf("| %-4d%-6d%-6d|  ", cashDesks[i].customers[cashDesks[i].frontIndex].id, cashDesks[i].customers[cashDesks[i].frontIndex].items, cashDesks[i].itemsCount);
                }
                roundCount++;
                continue;
            } else {
                customer = customerCreate(customersCount + 1, randomNumber(16, 2));
                cashDeskAdd(&cashDesks[selectedDesk], customer);
                customersCount++;
                for (i = 0; i < NO_OF_CASH_DESKS; i++)
                {
                    if (selectedDesk == i)
                    {
                        printf("| %-4d%-6d%-6d|  ", customer.id, customer.items, cashDesks[i].itemsCount);
                        roundCount++;
                        continue;
                    }
                    if (cashDeskIsEmpty(cashDesks[i]))
                    {
                        printf("| %-4d%-6d%-6d|  ", 0, 0, cashDesks[i].itemsCount);
                        continue;
                    }
                    printf("| %-4d%-6d%-6d|  ", cashDesks[i].customers[cashDesks[i].frontIndex].id, cashDesks[i].customers[cashDesks[i].frontIndex].items, cashDesks[i].itemsCount);
                } 
            }
        } else {
            customersServe(cashDesks);
            roundCount++;
        }
    } while (customersCount != NO_OF_CUSTOMERS);
    while (!cashDesksAllEmpty(cashDesks))
    {
        printf("\n%-7d%-6d%-7c ", roundCount, 0, '-');
        customersServe(cashDesks);
        roundCount++;
    }
    return 0;
}