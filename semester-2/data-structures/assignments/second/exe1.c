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

void nodeInsert (treeNode *root, treeNode *node);
treeNode *nodeCreate (student *stud);

int main(void) {
    // Variable declarations
    int i=1;
    FILE *fp;
    student *studentFile;
    treeNode *root;
    return 0;
}

void nodeInsert (treeNode *root, treeNode *node) {
    if (root->data->aem > node->data->aem) {
        if (root->nodeLeft != NULL) nodeInsert(root->nodeLeft, node);
        if (root->nodeLeft == NULL) root->nodeLeft = node;
    } else {
        if (root->nodeRight != NULL) nodeInsert(root->nodeRight, node);
        if (root->nodeRight == NULL) root->nodeRight = node;
    }
}

treeNode *nodeCreate (student *stud) {
    treeNode *node = malloc(sizeof(treeNode));
    node->data = stud;
    node->nodeLeft = NULL;
    node->nodeRight = NULL;
    return node;
}