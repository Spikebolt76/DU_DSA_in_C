#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    size_t size;
} Queue;

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q)
        return NULL;
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool is_empty(Queue *q) {
    return q->size == 0;
}

int peek(Queue *q) {
    if (is_empty(q))
    {
        printf("Queue is empty!\n");
        return -1; // Or some error code
    }
    return q->front->data;
}

void enqueue(Queue *q, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
        return;
    new_node->data = value;
    new_node->next = NULL;
    if (is_empty(q))
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

bool dequeue(Queue *q) {
    if (is_empty(q))
        return false;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->size == 0)
        q->rear = NULL;
    return true;
}

void free_queue(Queue *q) {
    while (!is_empty(q))
    {
        dequeue(q);
    }
    free(q);
}

void print_queue(Queue *q) {
    Node *curr = q->front;
    printf("Queue: ");
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print_queue(q);

    printf("Peek: %d\n", peek(q));
    dequeue(q);
    print_queue(q);
}