#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node *subLeft;
    struct Node *subRight;
};

// Usar alias "Tree" para representar árvore
typedef struct Node Tree;

Tree * init() {
    return NULL;
}

Tree * createNewNode(int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->subLeft = NULL;
    n->subRight = NULL;
    n->data = value;
    return n;
}

bool isEmpty(Tree *root) {
    return root == NULL;
}

Tree * insert(Tree *root, int value) {
    if (isEmpty(root))
        return createNewNode(value);

    if (value > root->data)
        root->subRight = insert(root->subRight, value);
    else
        root->subLeft = insert(root->subLeft, value);
    return root;
}

Tree * populateTree(Tree *root, int samples[], unsigned length) {
    for (int i = 0; i < length; i++)
        root = insert(root, samples[i]);
    return root;
}

void inOrder(Tree *root) {
    if (! isEmpty(root)) {
        inOrder(root->subLeft);
        printf("[%2i] ", root->data);
        inOrder(root->subRight);
    }
}

Tree * removeLeaves(Tree *root) {
    if (isEmpty(root))
        return NULL;

    if (root->subLeft == NULL && root->subRight == NULL) {
        free(root);
        root = NULL;
    }

    root->subLeft = removeLeaves(root->subLeft);
    root->subRight = removeLeaves(root->subRight);

    return root;
}

int main() {
    int vector[12] = {15, 16, 5, 20, 3, 12, 18, 13, 10, 23, 6, 7};

    Tree *root = init();

    root = populateTree(root, vector, 12);

    inOrder(root);
    printf("\n");
    removeLeaves(root);
    inOrder(root);


    return 0;
}