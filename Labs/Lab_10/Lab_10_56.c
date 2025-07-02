#include <stdio.h>
#include <stdlib.h>

// Write a program to implement a node structure for singly linked list. Read the data in a node, print the node.

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node node1;

int main() {

    node1.data = 42;
    node1.next = NULL;

    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter data for the node: ");
    scanf("%d", &node->data);

    node->next = NULL;

    printf("The node contains: %d\n", node->data);

    printf("Size of struct Node  = %d\n", sizeof(Node));
    
    printf("Size of struct Node pointer = %d\n", sizeof(node));

    printf("Size of struct Node instance = %d\n", sizeof(node1));

    free(node);

    return 0;
}
