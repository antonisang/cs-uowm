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
treeNode *nodeSeek (treeNode *root, unsigned int key, short int verbose);


int main(void) {
    // Variable declarations
    int i=1;
    FILE *fp;
    student *studentFile;
    treeNode *root;
    treeNode *targetStudent;

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

    // Query 1
    printf("****** QUERY 1 ******\n");
    targetStudent = nodeSeek(root, 4467, 0);
    printf("The grade of student with ID %d is %.2f", 4467, targetStudent->data->grade);

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

treeNode *nodeSeek (treeNode *root, unsigned int key, short int verbose) {
    if (verbose) printf("Comparing %i with %i -> ", root->data->aem, key);
    if (root->data->aem == key) {
        if (verbose) printf("Found key: %i", key);
        return root;
    } else if (root->data->aem > key) {
        if (verbose) printf("Node key is bigger than target key, going left...\n");
        if (root->nodeLeft != NULL) {
            nodeSeek(root->nodeLeft, key, verbose);
        } else {
            if (verbose) printf("No left node was found, the key is probably missing from the tree...\n");
            return NULL;
        }
    } else {
        if (verbose) printf("Node key is smaller than target key, going right...\n");
        if (root->nodeRight != NULL) {
            nodeSeek(root->nodeRight, key, verbose);
        } else {
            if (verbose) printf("No right node was found, the key is probably missing from the tree...\n");
            return NULL;
        }
    }
}