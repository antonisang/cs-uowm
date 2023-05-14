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

    // Open file
    fp = fopen("Students", "rb");

    // Create root node
    fseek(fp, 0, SEEK_SET);
    studentFile = malloc(sizeof(student));
    fread(studentFile, sizeof(student), 1, fp);
    root = nodeCreate(studentFile);

    // Insert nodes to tree
    while (1)
    {
        fseek(fp, i * sizeof(student), SEEK_SET);
        studentFile = malloc(sizeof(student));
        fread(studentFile, sizeof(student), 1, fp);
        // Break loop if EOF
        if (feof(fp)) break;
        nodeInsert(root, nodeCreate(studentFile));
        i++;
    }

    fclose(fp);
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