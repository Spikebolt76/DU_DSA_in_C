#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    struct Node* root;
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


