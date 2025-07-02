#include "linkedlist.h"

// Write a program to copy a linked list.

int main()
{
    LinkedList list;
    LinkedList copy;
    initList(&list);
    initList(&copy);

    printf("Enter data to linkedlist-1 : ");
    takeUserInput(&list, 1);

    copyList(&list, &copy);

    display(&list);
    display(&copy);
}