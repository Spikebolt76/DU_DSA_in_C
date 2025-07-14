#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    size_t size;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed for stack\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool is_empty(const Stack* stack) {
    return stack->top == NULL;
}

size_t size(const Stack* stack) {
    return stack->size;
}

void push(Stack* stack, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed for node\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack underflow: Cannot pop from empty stack\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

int top(const Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack is empty: No top element\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

void free_stack(Stack* stack) {
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}

void print_stack(const Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = create_stack();

    printf("Pushing 10, 20, 30\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_stack(stack);
    printf("Size: %zu\n", size(stack));

    printf("Top element: %d\n", top(stack));

    printf("Popped: %d\n", pop(stack));
    print_stack(stack);
    printf("Size: %zu\n", size(stack));

    printf("Popped: %d\n", pop(stack));
    print_stack(stack);

    printf("Popped: %d\n", pop(stack));
    print_stack(stack);

    printf("Is empty: %s\n", is_empty(stack) ? "Yes" : "No");

    free_stack(stack);
}