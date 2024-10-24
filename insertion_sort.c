#include "insertion_sort.h"
#include <stdio.h>

node* isort(node *list) {
    if (list == NULL || list->next == NULL) {
        // List is already sorted if it's empty or contains only one node
        return list;
    }

    // Initialize sorted linked list
    node *sorted = NULL;
    node *current = list;

    // Traverse the original list and insert each node into the sorted list
    while (current != NULL) {
        // Save the next node to continue traversal later
        node *next = current->next;

        // Insert the current node into the sorted part of the list
        if (sorted == NULL || sorted->data >= current->data) {
            // Insert at the beginning of the sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // Find the position to insert the current node in the sorted list
            node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            // Insert the node at the correct position
            current->next = temp->next;
            temp->next = current;
        }

        // Move to the next node in the unsorted list
        current = next;
    }

    // Return the head of the sorted list
    return sorted;
}