#pragma once

#include <stdbool.h>

#include "node.h"

#include "stack.h"
 
typedef struct queue {
  int size;
  stack *stack1;
  stack *stack2;
} queue;

void initialize(queue *q);
bool empty(const queue *q);
bool full(const queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
