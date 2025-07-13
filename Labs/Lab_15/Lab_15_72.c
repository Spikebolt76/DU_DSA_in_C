#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} DoublyLinkedList;

DoublyLinkedList* init_DoublyList () {
    DoublyLinkedList* list = (DoublyLinkedList*) malloc (sizeof(DoublyLinkedList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for doubly linked list\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

bool is_empty(const DoublyLinkedList* list) {
    return list->head == NULL;
}

size_t size(const DoublyLinkedList* list) {
    return list->size;
}

void insertAtHead (DoublyLinkedList* list, int val) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        exit(EXIT_FAILURE); // evaluates to exit(1)
    }
    newNode->data = val;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (is_empty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

void insertAtTail (DoublyLinkedList* list, int val) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        exit(EXIT_FAILURE); 
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (is_empty(list)) {
        list->tail = newNode;
        list->head = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

bool delete_head (DoublyLinkedList* list) {
    if (is_empty(list)) {
        fprintf(stderr, "List is empty: Cannot delete head\n");
        return false;
    }
    Node* temp = list->head;
    list->head = list->head->next;

    if (list->head)
        list->head->prev = NULL;
    else   
        list->tail = NULL;

    free(temp);
    list->size--;
    return true;
}

bool delete_tail (DoublyLinkedList* list) {
    if (is_empty(list)) {
        fprintf(stderr, "List is empty: Cannot delete head\n");
        return false;
    }
    Node* temp = list->tail;
    list->tail = list->tail->prev;

    if (list->tail) 
        list->tail->next = NULL;
    else 
        list->head = NULL;
        
    free(temp);
    list->size--;
    return true;
}

bool delete_at (DoublyLinkedList* list, int index) {
    if (is_empty(list)) {
        fprintf(stderr, "List is empty: Cannot delete at position\n");
        return false;
    }
    if (index >= list->size) {
        fprintf(stderr, "Invalid position: %zu, size: %zu\n", index, list->size);
        return false;
    }

    if (index == 0) {
        return delete_head(list);
    }
    if (index == list->size - 1) {
        return delete_tail(list);
    }

    Node* curr = list->head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    list->size--;
    return true;
}

void print_list_forward(const DoublyLinkedList* list) {
    if (is_empty(list)) {
        printf("Doubly Linked List is empty\n");
        return;
    }
    printf("Doubly Linked List (forward): ");
    Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void print_list_backward(const DoublyLinkedList* list) {
    if (is_empty(list)) {
        printf("Doubly Linked List is empty\n");
        return;
    }
    printf("Doubly Linked List (backward): ");
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

//=--------------------------------------------------------------------------------
  
int main () {

    printf("%d %d", EXIT_FAILURE, EXIT_SUCCESS);

    DoublyLinkedList* list1;
    list1 = init_DoublyList();

    insertAtTail(list1, 23);    
    insertAtTail(list1, 45);    
    insertAtTail(list1, 27);    
    insertAtTail(list1, 0);    
    insertAtTail(list1, 93);    
    insertAtTail(list1, 12);    

    print_list_forward(list1);
    print_list_backward(list1);

    return 0;
}