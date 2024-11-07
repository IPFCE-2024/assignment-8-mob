#include "stack.h"
#include <stdlib.h>

void stack_initialize(stack *s) {
  s->head = NULL; // Initialize stack head
}

void stack_push(int x, stack *s) {
  node *new = (node *)malloc(sizeof(node)); // create new node
  new->data = x; // Add data to new node
  new->next = s->head; // Set next to NULL
  s->head = new; // Point header to newest node
}

int stack_pop(stack *s) {
  // implement pop here
  if (s->head == NULL) {
    return -1;
  }
  int pop_value = s->head->data; // Variable for value stored in popped node
  node *temp = s->head; // Save pointer for node for free()
  s->head = s->head->next; // Set header to point to new newest
  free(temp); // Free memory from popped node
  return pop_value; // Return popped value
}

bool stack_empty(stack *s) {
  return s->head == NULL; // Return wether empty
}

bool stack_full(stack *s) {
  // implement full here
  return false; // The stack cant be full.
}