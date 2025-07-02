#include "linkedlist.h"

int main () {
    
    LinkedList list;
    initList(&list);
    printf("Enter (sorted) data to linkedlist : ");

    takeUserInput(&list, 1);

    printf("\nOriginal LinkedList : ");
    display(&list);

    Node* ptr = list.head;

    while (ptr && ptr->next) {
        if (ptr->data == ptr->next->data) {
            ptr->next = ptr->next->next;
        } else {
            ptr = ptr->next;
        }
    }

    printf("\nSorted LinkedList after deleting dupes : ");
    display(&list);

}