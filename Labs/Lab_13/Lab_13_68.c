#include "linkedlist.h"

// Write a program to swap two consecutive nodes in the linked list. 
// Don’t change the values of nodes, implement by changing the link of the nodes.

void swapNodes (LinkedList* list) {

    if (!list->head || !list->head->next) return;

    Node dummy;
    Node* curr = list->head;
    Node* prev = &dummy;

    while (curr && curr->next) {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = curr->next;
    }
    list->head = dummy.next;
}

int main () {
    LinkedList list;
    initList(&list);

    takeUserInput(&list, 1);

    printf("\nLinkedList before Swapping : ");
    display(&list);

    swapNodes(&list);

    printf("\nLinkedList after swapping adjacent nodes : ");
    display(&list);
}