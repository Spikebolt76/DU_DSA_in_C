#include "linkedlist.h"

// Write a program to sort elements of a linked list.

Node* getMiddle (LinkedList* list);

void merge(LinkedList* left, LinkedList* right, LinkedList* list);

void mergeSort (LinkedList* list);

void mergeSort (LinkedList* list) {
    if (!list->head || !list->head->next) 
        return;

    Node* middle = getMiddle(list);
    Node* rightHead = middle->next; 
    middle->next = NULL;          
    LinkedList left, right;
    left.head = list->head;
    right.head = rightHead;

    mergeSort(&left);
    mergeSort(&right);
    merge(&left, &right, list);
}

void merge(LinkedList* left, LinkedList* right, LinkedList* list) {
    Node dummy;
    Node* curr = &dummy;
    Node* Lptr = left->head;
    Node* Rptr = right->head;

    while (Lptr && Rptr) {
        if (Lptr->data <= Rptr->data) {
            curr->next = Lptr;
            Lptr = Lptr->next;
        } else {
            curr->next = Rptr;
            Rptr = Rptr->next;
        }
        curr = curr->next;

    }

    curr->next = Lptr ? Lptr : Rptr; 

    list->head = dummy.next;
    left->head = NULL;  
    right->head = NULL;
}

Node* getMiddle (LinkedList* list) {
    if (!list->head || !list->head->next) return list->head;

        Node* slow = list->head;
        Node* fast = list->head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    return slow;
}

int main () {
    LinkedList list;
    initList(&list);

    takeUserInput(&list, 1);

    printf("\nLinkedList before Sorting : ");
    display(&list);

    mergeSort(&list);

    printf("\nLinkedList after Sorting : ");
    display(&list);

    return 0;
}