#include "queue.h"
#include <stdlib.h>
#include <assert.h>


void initialize(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    return (q->size == 0);
}

bool full(const queue *q) {
    return false;  // The queue can't be "full" in a linked list implementation
}

void enqueue(queue *q, int x) {
    node *newNode = (node *)malloc(sizeof(node));
    assert(newNode != NULL);  // Ensure memory allocation was successful
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Attach the new node to the end of the queue and update the rear
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// Function to dequeue an element (remove from the front)
int dequeue(queue *q) {
    assert(!empty(q));  // Ensure the queue is not empty

    node *temp = q->front;
    int data = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;  // If the queue becomes empty, set rear to NULL as well
    }

    free(temp);
    q->size--;

    return data;
}
