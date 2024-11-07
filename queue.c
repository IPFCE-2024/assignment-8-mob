#include "queue.h"
#include <stdlib.h> // NULL
#include <stdio.h> // printf

void initialize(queue *q) {
    // Initialize queue by setting size to 0
    q->size = 0;
    // Initialize pointers for front and rear to NULL
    q->front = NULL;
    q->rear = NULL;
}

bool empty(const queue *q) {
    // Returns wether queuesize is 0; queue is empty
    return (q->size == 0);
}

bool full(const queue *q) {
    // Queue cant be full; return false
    return false;
}

void enqueue(queue *q, int x) {
    // If queue is full; print error
    if (full(q)) {
        printf("Queue is full");
        abort();
    }
    // Create new node to insert in queue
    node *new_node = malloc(sizeof(node));
    // Insert value in data of new node and set next to NULL
    new_node->data = x;
    new_node->next = NULL;
    if (empty(q)) { // If queue is empty; initialize front and rear
        q->front = new_node;
    } else { // Else add node in rear of queue
        q->rear->next = new_node;
    }
    // Set new node as rear of queue
    q->rear = new_node;
    // Add 1 to size of queue
    q->size++;
}

int dequeue(queue *q) {
    if (empty(q)) {
        printf("Queue is empty");
        abort();
    }
    node *old_front = q->front;
    // Set 2nd in queue as front, will assign NULL if empty
    q->front = q->front->next;
    // Remove 1 from size of queue
    q->size--;
    if (empty(q)) { // If queue is now empty; set rear to NULL
        q->rear = NULL;
    }
    // Initialize placeholder for data in old front and free memory
    int old_front_data = old_front->data;
    free (old_front);
    // Return front of queue
    return old_front_data;
}