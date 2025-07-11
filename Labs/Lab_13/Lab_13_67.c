#include "linkedlist.h"
// WAP to perform given operation in the linked list. There exist a Linked List. 
// Add a node that contains the GCD of that two nodes between every pair adjacent node of Linked List.

int getGCD (int a, int b);

void insertGCD (LinkedList* list) {
    if (!list->head && !list->head->next) return;

    Node* curr = list->head;

    while (curr && curr->next) {
        Node* newNode = malloc (sizeof(Node));
        newNode->data = getGCD(curr->data, curr->next->data);

        Node* temp = curr->next;
        curr->next = newNode;
        newNode->next = temp;

        curr = temp;
    }
}

int getGCD (int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main () {
    LinkedList list; 
    initList(&list); 
    
    takeUserInput(&list, 1);

    printf("\nLinkedList before Insertion : ");
    display(&list);

    insertGCD(&list);

    printf("\nLinkedList after Insertion : ");
    display(&list);

    return 0;
}