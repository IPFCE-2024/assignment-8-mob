#include "queue_stack.h"
#include <stdlib.h> // NULL
#include "stack.h"

void initialize(queue *q) {
    q->size = 0;
    q->stack1 = malloc(sizeof(stack));
    q->stack2 = malloc(sizeof(stack));
    stack_initialize(q->stack1);
    stack_initialize(q->stack2);
}

bool empty(const queue *q) {
    return (stack_empty(q->stack1) && stack_empty(q->stack2));
}

bool full(const queue *q) {
    return false;
}

void enqueue(queue *q, int x) {
    // If queue is full; print error
    if (full(q)) {
        printf("Queue is full");
        abort();
    }
    stack_push(x, q->stack1);
    q->size++;
}

int dequeue(queue *q) {
    // If queue is empty; print error
    if (empty(q)) {
        printf("Queue is empty");
        abort();
    }
    for (int i = 1; i < q->size; i++) {
        stack_push(stack_pop(q->stack1), q->stack2);
    }
    int value = stack_pop(q->stack1);
    for (int i = 1; i < q->size; i++) {
        stack_push(stack_pop(q->stack2), q->stack1);
    }
    q->size--;
    return value;
}