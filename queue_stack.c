#include <stdlib.h>
#include <assert.h>
#include "queue_stack.h"

// Initialize the queue by initializing both stacks
void initialize(queue *q) {
    initialize(&q->s1);
    initialize(&q->s2);
}

// Check if the queue is empty by checking both stacks
bool empty(const queue *q) {
    return empty(&q->s1) && empty(&q->s2);
}

// Since we're using linked lists for stacks, the queue is never full
bool full(const queue *q) {
    return false;  // The queue can't be "full" in a linked list implementation
}

// Enqueue operation: Push the element onto stack s1
void enqueue(queue *q, int x) {
    push(&q->s1, x);
}

// Dequeue operation: Pop from stack s2 if not empty; otherwise, transfer elements
int dequeue(queue *q) {
    if (empty(&q->s2)) {
        // Transfer all elements from s1 to s2
        while (!empty(&q->s1)) {
            int data = pop(&q->s1);
            push(&q->s2, data);
        }
    }
    // Now pop the element from s2
    return pop(&q->s2);
}
