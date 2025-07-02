#include "linkedlist.h"

int main () {
    
    LinkedList list1;
    initList(&list1);
    LinkedList list2;
    initList(&list2);

    printf("Enter data to linkedlist-1 : ");
    takeUserInput(&list1, 1);

    printf("Enter data to linkedlist-2 : ");
    takeUserInput(&list2, 1);

    compareLists(&list1, &list2);
}