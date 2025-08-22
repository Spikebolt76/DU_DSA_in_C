#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
 } Tree;

Node* newNode (int data) {
    Node* node = (Node*) malloc (sizeof(Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertLeft (Node* parent, int data) {
    parent->left = newNode(data);
    return parent->left;
}

Node* insertRight (Node* parent, int data) {
    parent->right = newNode(data);
    return parent->right;
}

void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void displayTree (Node* root) {
    if (root == NULL) {
        printf("NULL");
        return;
    }

    printf("%d", root->data);
    
    if (root->left || root->right) {
        printf(" -> (L: ");
        displayTree(root->left);

        printf(", R: ");
        displayTree(root->right);
        printf(")");
    }
}

int main () {
    Tree tree;
    tree.root = newNode(1);

    Node* l1 = insertLeft(tree.root, 2);
    Node* r1 = insertRight(tree.root, 3);
    Node* l2 = insertLeft(l1, 4);
    Node* r2 = insertRight(l1, 5);
    Node* l3 = insertLeft(r1, 6);

    displayTree(tree.root);

    freeTree(tree.root);

    return 0;
}