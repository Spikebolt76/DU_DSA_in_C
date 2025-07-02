#include <stdio.h>
#include "linkedlist.h"

int main() {
    LinkedList list;
    initList(&list);

    int choice, value, position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Delete from Specified Position\n");
        printf("6. Display List\n");
        printf("7. Count Nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(&list, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&list, value);
                break;
            case 3:
                deleteFromFront(&list);
                break;
            case 4:
                deleteFromEnd(&list);
                break;
            case 5:
                printf("Enter position to delete (0-based): ");
                scanf("%d", &position);
                deleteAtPosition(&list, position);
                break;
            case 6:
                display(&list);
                break;
            case 7:
                printf("Number of nodes: %d\n", size(&list));
                break;
            case 0:
                destroyList(&list);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
