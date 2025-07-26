#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void change(Stack* s, int iFromTop, int value);
int size(Stack* s);
void display(Stack* s);
void clearStack(Stack* s);

void initStack (Stack* s) {
    s->top = -1;
}

bool isEmpty (Stack* s) {
    return s->top == -1;
}

bool isFull (Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push (Stack* s, int value) {
    if (isFull(s)) {
        fprintf(stderr, "Stack Overflow! Cannot push %d\n", value);
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
    printf("Pushed %d in stack\n", value);
}

int pop (Stack* s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack Overflow! Cannot pop from empty stack\n");
        exit(EXIT_FAILURE);
    }
    int value = s->data[s->top--];
    printf("Popped %d from stack\n", value);
    return value;
}

int peek (Stack* s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack Overflow! Cannot pop from empty stack\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

int size (Stack* s) {  //current number of elements inside stack
    return s->top + 1;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack contents (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void clearStack(Stack* s) {
    s->top = -1;
    printf("Stack cleared\n");
}

// Changes ith element from top to passed value
void change(Stack* s, int iFromTop, int value) {
    if (iFromTop >= s->top || iFromTop < 0) {
        fprintf(stderr, "Stack index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    int index = s->top - 1 - iFromTop;
    s->data[index] = value;
}


