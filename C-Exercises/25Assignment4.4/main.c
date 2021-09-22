#include <stdio.h>


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

Tree * populateTree(Tree *root, int samples[], unsigned length) {
    for (int i = 0; i < length; i++)
        root = insert(samples[length]);
    return root;
}

int main() {
    const unsigned length = 12;
    int vector[length] = {15, 16, 5, 20, 3, 12, 18, 13, 10, 23, 6, 7};

    Tree *root = init();

    root = populateTree(root, vector, length);

    // Next: print it...

    return 0;
}