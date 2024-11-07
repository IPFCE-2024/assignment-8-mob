#pragma once

#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct {
  node *head;
} stack;

void stack_initialize(stack *s);
void stack_push(int element, stack *s);
int stack_pop(stack *s);
bool stack_empty(stack *s);
bool stack_full(stack *s);
