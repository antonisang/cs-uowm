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

int main(void) {
    // Variable declarations
    int i=1;
    FILE *fp;
    student *studentFile;
    treeNode *root;
    return 0;
}
