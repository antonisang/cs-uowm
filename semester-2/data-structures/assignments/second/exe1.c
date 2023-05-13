#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[56];
    float grade;
    unsigned int aem;
} student;

typedef struct {
    student data;
    treeNode *nodeLeft;
    treeNode *nodeRight;
} treeNode;
