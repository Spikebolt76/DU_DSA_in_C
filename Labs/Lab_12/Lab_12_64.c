#include "linkedlist.h"

int main() {
    // Write a program to reverse a linked list.

    LinkedList list;
    initList(&list);

    printf("Enter data to linkedlist : ");
    takeUserInput(&list, 1);

    printf("Original LinkedList : ");
    display(&list);

    Node* curr = list.head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.head = prev;

    printf("Reversed LinkedList : ");
    display(&list);
}