#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[56];
    float grade;
    unsigned int aem;
} student;

typedef struct treeNode {
    student *data;
    struct treeNode *nodeLeft;
    struct treeNode *nodeRight;
} treeNode;
