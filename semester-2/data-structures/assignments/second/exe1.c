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
void _inorderAverage (treeNode *root, unsigned int start, unsigned int end, float *sum, int *count, int *compCount);
float rangeAverage (treeNode *root, unsigned int start, unsigned int end);


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
    // Query 2
    printf("\n\n****** QUERY 2 ******\n");
    targetStudent = nodeSeek(root, 4467, 1);
    // Query 3
    printf("\n\n****** QUERY 3 ******\n");
    printf("\n\nUsing the in-order traversal method we get that the average \ngrade of students in range 4001-4220 is: %.2f", rangeAverage(root, 4001, 4220));


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

void _inorderAverage (treeNode *root, unsigned int start, unsigned int end, float *sum, int *count, int *compCount) {
    if (root == NULL) return;
    _inorderAverage(root->nodeLeft, start, end, sum, count, compCount);
    // If AEM is in range...
    printf("Comparing if %i is in range of %i - %i...", root->data->aem, start, end);
    (*compCount)++;
    if (root->data->aem >= start && root->data->aem <= end) {
        printf("IT IS\n");
        // ...add root->data->grade to sum and increment by 1 the count
        (*sum) += root->data->grade;
        (*count)++;
    } else printf("IT'S NOT\n");
    _inorderAverage(root->nodeRight, start, end, sum, count, compCount);
}

float rangeAverage (treeNode *root, unsigned int start, unsigned int end) {
    int count=0, compCount=0;
    float sum=0;

    // Pass the memory address of sum, count and compCount in 
    // order to allow _inorderAverage to modify the values of 
    // sum, count and compCount
    _inorderAverage(root, start, end, &sum, &count, &compCount);

    // Case count == 0, no nodes found within range
    if (!count) return 0;

    printf("\nTotal number of comparisons: %d\n", compCount);
    printf("Time complexity is: O(n)");

    return sum/count;
}
