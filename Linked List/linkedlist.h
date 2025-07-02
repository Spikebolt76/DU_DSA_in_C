#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

/// @brief Initializes an empty linked list.
/// @param list Pointer to the LinkedList to initialize.
void initList(LinkedList* list) {
    list->head = NULL;
}

/// @brief Inserts a new node at the front of the list.
/// @param list Pointer to the LinkedList.
/// @param value Integer value to insert.
void insertAtFront(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

/// @brief Inserts a new node at the end of the list.
/// @param list Pointer to the LinkedList.
/// @param value Integer value to insert.
void insertAtEnd(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/// @brief Deletes the first node from the list.
/// @param list Pointer to the LinkedList.
void deleteFromFront(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

/// @brief Deletes the last node from the list.
/// @param list Pointer to the LinkedList.
void deleteFromEnd(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

/// @brief Deletes a node at the specified 0-based position.
/// @param list Pointer to the LinkedList.
/// @param position Position of the node to delete.
void deleteAtPosition(LinkedList* list, int position) {
    if (position < 0 || list->head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }

    if (position == 0) {
        deleteFromFront(list);
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;
    int index = 0;

    while (current != NULL && index < position) {
        prev = current;
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

/// @brief Displays all elements of the linked list.
/// @param list Pointer to the LinkedList.
void display(LinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/// @brief Frees all nodes and resets the list to empty.
/// @param list Pointer to the LinkedList.
void destroyList(LinkedList* list) {
    while (list->head) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

/// @brief Counts and returns the number of nodes in the list.
/// @param list Pointer to the LinkedList.
/// @return Number of elements in the list.
int size(LinkedList* list) {
    Node* current = list->head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/// @brief Reverses the entire linked list.
/// @param list Pointer to the LinkedList.
void reverse(LinkedList* list) {
    Node* prev = NULL;
    Node* curr = list->head;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

/// @brief Takes user input to insert multiple elements into the list.
/// @details Based on mode: inserts at front, end, or a specific position for each value.
/// @param list Pointer to the LinkedList.
/// @param mode Insertion mode: 
/// - 0 = insert at front
/// - 1 = insert at end
/// - 2 = insert at user-specified position for each element
void takeUserInput(LinkedList* list, int mode) {
    int n, value, position;

    printf("How many elements to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value);

        if (mode == 0) {
            insertAtFront(list, value);
        } else if (mode == 1) {
            insertAtEnd(list, value);
        } else if (mode == 2) {
            printf("Enter position to insert at (0-based): ");
            scanf("%d", &position);
            insertAtPosition(list, value, position);
        } else {
            printf("Invalid mode! Use:\n 0 = front\n 1 = end\n 2 = position\n");
            return;
        }
    }
}


/// @brief Inserts a new node at a specified position in the list.
/// @param list Pointer to the LinkedList.
/// @param value Integer value to insert.
/// @param position 0-based index where to insert the new node. If position > size, inserts at end.
void insertAtPosition(LinkedList* list, int value, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    // Inserting at the front
    if (position == 0 || list->head == NULL) {
        insertAtFront(list, value);
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    Node* current = list->head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // If position is beyond list size, insert at end
    if (current == NULL) {
        insertAtEnd(list, value);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

/// @brief Compares two linked lists for equality.
/// @param list1 Pointer to the first LinkedList.
/// @param list2 Pointer to the second LinkedList.
/// @return 1 if lists are identical, 0 otherwise.
int compareLists(LinkedList* list1, LinkedList* list2) {
    Node* curr1 = list1->head;
    Node* curr2 = list2->head;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data != curr2->data) {
            return 0; // Data mismatch
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // If both reached NULL at same time, they're equal
    return (curr1 == NULL && curr2 == NULL);
}

/// @brief Sorts the linked list in ascending order using bubble sort.
/// @param list Pointer to the LinkedList.
void sortList(LinkedList* list) {
    if (list->head == NULL || list->head->next == NULL) {
        return; // Already sorted or empty
    }

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}



#endif // LINKEDLIST_H
