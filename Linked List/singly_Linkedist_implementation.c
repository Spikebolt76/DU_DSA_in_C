#include <stdio.h>
#include <stdlib.h>

// Defining a node 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Defining a LinkedList (type) structure :-
/*
The LinkedList struct acts as a wrapper for your linked list. Its main purpose is to hold a pointer to the first node (head) of the list.

Why use it?
- It makes your code more modular and organized.
- You can easily pass the whole list (not just a node) to functions.
- You can add more metadata later (like size, tail, etc.) if needed.

Now, LinkedList represents the entire list, and head points to the first node.
This is better than just using a Node* everywhere, especially as your code grows.

*/
typedef struct {
    Node* head;
} LinkedList;

// Initialize an empty LinkedList
void initList(LinkedList* list) {
    list->head = NULL;
}

// Insert at the beginning :-
void insertAtFront (LinkedList* list, int value) {
    Node* newNode = (Node*) malloc (sizeof(Node)); //allocate memory

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

// Insert at the end :-
void insertAtEnd (LinkedList* list, int value) {
    Node* newNode = (Node*) malloc (sizeof(Node)); //allocate memory

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL){
        newNode = list->head;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;   
}

// Delete from front :-
void deleteFromFront (LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;
    list->head = list->head->next;
    free(current);
}

// Delete from End :-
void deleteFromEnd (LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Case 1: Only one node in the list
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    // Case 2: More than one node
    Node* current = list->head;
    Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

// Display/print the whole LinkedList :-  
// You cannot access list->data because LinkedList does not have a data field. 
// Only the Node struct has a data field.
// to display the linkedlist :
// Create a temporary pointer (e.g., Node* current) and set it to list->head.
// Traverse the list using this pointer.
// Access current->data for each node.

void display(LinkedList* list) {
    Node* current = list->head;

    if (current == NULL){
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Delete the whole linkedlist :-
void destroyList (LinkedList* list) {
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}
  
// Count Node = Size of list :-
int size (LinkedList* list) {
    Node* current = list->head;
    int i = 0;

    if (current == NULL) {
        return 0;
    }
    while (current != NULL) {
        current = current->next;
        i++;
    }
    return i;
} 

// Reverse the linkedlist :-
void reverse (LinkedList* list) {
    Node* prev = NULL;
    Node* curr = list->head;
    // Node* next = NULL;
    
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

LinkedList* merge (LinkedList* l1, LinkedList* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    // Choose the head of the merged list
    Node* h1 = l1->head;
    Node* h2 = l2->head;
    Node* head = NULL;  // head of the to-be-merged list 

    if (h1->data < h2->data) {
        head = h1;
        h1 = h1->next;
    } else {
        head = h2;
        h2 = h2->next;
    }
    Node* curr = head;

    while (h1 != NULL && h2 != NULL) {

        if (h1->data < h2->data) {
            curr->next = h1;
            h1 = h1->next;
        }
        else {
            curr->next = h2;
            h2 = h2->next;
        }
        curr = curr->next;
    }

    LinkedList* result = (LinkedList*) malloc(sizeof(LinkedList));
    // result->head = mergedHead;
    return result;
}

// main function
int main() {
    LinkedList list;
    initList(&list);

    insertAtFront(&list, 1);
    insertAtFront(&list, 4);
    insertAtFront(&list, 5);
    insertAtEnd(&list, 6);
    display(&list);
    printf("%d\n", size(&list));
    reverse(&list);
    display(&list);
}


/*
Metadata means "data about data."
In the context of your LinkedList struct, metadata refers to extra information about the list itself, not just the nodes.

Examples of metadata you might add:

-- int size; // Number of nodes in the list
-- Node* tail; // Pointer to the last node for fast insertions at the end
-- Adding metadata makes your linked list more powerful and efficient for certain operations.
*/