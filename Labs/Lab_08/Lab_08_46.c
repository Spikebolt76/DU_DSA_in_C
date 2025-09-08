#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init_Queue (Queue* q) {
    q->front = -1;
    q->rear = 0;
}

bool isEmpty (Queue* q) {
    return q->front == -1 ;
}

bool isFull (Queue* q) {
    return q->rear == MAX_SIZE;
}

// Inserts an element in the queue through rear pointer.
void enqueue (Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear++;
}

// Removes an element from the queue through front pointer.
void dequeue (Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    q->front++;
}

int peek (Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front + 1];
}

void printQueue (Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    for () {
        
    }
}
// Queue Implimentation :-
int main () {


    return 0;
}