#include "linkedlist.h"

int main() {
    // WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

    LinkedList list;
    initList(&list);

    printf("Enter data to linkedlist : ");
    takeUserInput(&list, 1);

    int k;
    printf("\nEnter K (position): ");
    scanf("%d", &k);

    int n = sizeOfList(&list);

    if (k <= 0 || k > n) {
        printf("Invalid position.\n");
        return 1;
    }

    int inxF = k - 1;
    int inxE = n - k;

    if (inxF == inxE) {
        printf("Same node. No need to swap.\n");
        display(&list);
        return 0;
    }

    Node *prevF = NULL, *prevE = NULL, *curr = list.head;
    Node *swapF = NULL, *swapE = NULL;

    for (int i = 0; curr != NULL; i++) {
        if (i == inxF - 1)
            prevF = curr;
        if (i == inxF)
            swapF = curr;

        if (i == inxE - 1)
            prevE = curr;
        if (i == inxE)
            swapE = curr;

        curr = curr->next;
    }

    if (!swapF || !swapE) {
        printf("Swap positions invalid.\n");
        return 1;
    }

    if (prevF != NULL)
        prevF->next = swapE;
    else
        list.head = swapE;

    if (prevE != NULL)
        prevE->next = swapF;
    else
        list.head = swapF;

    Node* temp = swapF->next;
    swapF->next = swapE->next;
    swapE->next = temp;

    printf("\nList after swapping:\n");
    display(&list);

    return 0;
}
