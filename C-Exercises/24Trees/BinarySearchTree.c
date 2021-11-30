#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *subLeft;
    struct Node *subRight;
};

typedef struct Node * Tree;

Tree init() {
    return NULL;
}

bool isEmpty(Tree root) {
    return root == NULL;
}

Tree createNewNode(int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->subLeft = NULL;
    n->subRight = NULL;
    n->data = value;
    return n;
}

Tree find(Tree root, int value) {
    if (isEmpty(root) || root->data == value)
        return root;

    if (value > root->data)
        return find(root->subRight, value);

    return find(root->subLeft, value);
}

Tree insert(Tree root, int value) {
    if (isEmpty(root))
        return createNewNode(value);

    if (value > root->data)
        root->subRight = insert(root->subRight, value);
    else
        root->subLeft = insert(root->subLeft, value);
    return root;
}

void inOrder(Tree root) {
    if (! isEmpty(root)) {
        inOrder(root->subLeft);
        printf("[%2i] ", root->data);
        inOrder(root->subRight);
    }
}

void preOrder(Tree root) {
    if (! isEmpty(root)) {
        printf("[%2i] ", root->data);
        preOrder(root->subLeft);
        preOrder(root->subRight);
    }
}

void postOrder(Tree root) {
    if (! isEmpty(root)) {
        postOrder(root->subLeft);
        postOrder(root->subRight);
        printf("[%2i] ", root->data);
    }
}

Tree findSmallest(Tree temp) {
    while (temp->subLeft != NULL)
        temp = temp->subLeft;
    return temp;
}

Tree findGreater(Tree temp) {
    while (temp->subRight != NULL)
        temp = temp->subRight;
    return temp;
}

int main() {
    Tree root = init();

    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 13);
    root = insert(root, 25);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 31);

    printf("\n\nEm ordem:");
    inOrder(root);

    printf("\n\nPre ordem:");
    preOrder(root);

    printf("\n\nPos ordem:");
    postOrder(root);

    printf("\n");

    // while (true) {
    //     Tree temp = NULL;
    //     int value = 0;

    //     printf("\nInforme o valor: ");
    //     scanf("%i", &value);
    //     if (value == 0)
    //         break;

    //     temp = find(root, value);
    //     if (temp)
    //         printf("\nValor %i encontrado!!\n", temp->data);
    //     else
    //         printf("\nValor %i NAO encontrado!!\n", value);
    // }

    // if (! isEmpty(root)) {
    //     Tree temp = NULL;
    //     temp = findSmallest(root);
    //     printf("\nMenor valor %i encontrado!!\n", temp->data);

    //     temp = findGreater(root);
    //     printf("\nMaior valor %i encontrado!!\n", temp->data);
    // }
    return 0;
}
