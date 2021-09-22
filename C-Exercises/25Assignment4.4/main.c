#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./utilityFunctions.c"


int countLeaves(Tree *root) {
    if (isEmpty(root))
        return 0;

    if (root->subLeft == NULL && root->subRight == NULL)
        return 1;

    return countLeaves(root->subLeft) + countLeaves(root->subRight);
}

int main() {
    int vector[12] = {15, 16, 5, 20, 3, 12, 18, 13, 10, 23, 6, 7};

    Tree *root = init();

    root = populateTree(root, vector, 12);

    inOrder(root);
    printf("\n");
    printf("O numero de folhas eh: %d\n", countLeaves(root));

    return 0;
}