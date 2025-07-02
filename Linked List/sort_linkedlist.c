#include "linkedlist.h"

int main () {
    LinkedList list;
    initList(&list);

    takeUserInput(&list, 1);

    Node* ptr1 = list.head;
    Node* ptr2 = list.head;

    for (ptr1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                int temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }

    display(&list);
}