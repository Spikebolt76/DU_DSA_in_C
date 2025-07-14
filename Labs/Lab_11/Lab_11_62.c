#include "linkedlist.h"

// 1. bruteforce [O(n^2)] :-

void delete_duplicates (LinkedList* list) {
    if (!list->head || !list->head->next) return;

    Node* curr1 = list->head;
    while (curr1) {

        Node* curr2 = curr1;
        while (curr2->next) {
            if (curr1->data == curr2->next->data) {
                Node* dupe = curr2->next;  
                curr2->next = curr2->next->next;

                free(dupe);
            } else {
                curr2 = curr2->next;
            }
        }
        curr1 = curr1->next;
    }
}

int main () {
    LinkedList list;
    initList(&list);

    insertAtEnd(&list, 56);
    insertAtEnd(&list, 0);
    insertAtEnd(&list, 61);
    insertAtEnd(&list, 56);
    insertAtEnd(&list, 56);
    insertAtEnd(&list, 12);
    insertAtEnd(&list, -45);

    display(&list);
    delete_duplicates(&list);
    display(&list);

    return 0;
}