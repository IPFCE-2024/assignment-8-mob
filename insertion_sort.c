#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

node* isort(node *list) {
    // If the list is empty or only has one node; list is already sorted
    if (list == NULL || list->next == NULL) {
        return list;
    }
    // Initialize pointer node for header of list
    node *head = list;
    // Initialize current node
    node *current = list->next;
    // Initialize prev in order to prevent errors
    node *prev = list;
    // While loop that sorts the list by changing pointers of nodes in list
    while (current != NULL) {
        // Store next node of original list
        node *next = current->next;
        // If current node is smallest; place first and reassign pointer node for header
        if (current->data < head->data) {
            // Set current node to point to previous header node
            current->next = head;
            // Set pointer node for header to point at new header node
            head = current;
            // Remove current from its original position
            prev->next = next;
        } else {
            // Initialize pointer node for going through already sorted list
            node *temp = head;
            // Locate the node that should be right before current
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            if (temp->next != current) {
                // Place current node after temp and reassign pointers
                current->next = temp->next;
                temp->next = current;
                // Remove current from its original position
                prev->next = next;
            } else {
                prev = current;  // Keep prev if current is not moved
            }
        }
        // Prepare current for next iteration, taking next in original list
        current = next;
    }
    // Return pointer node for header of list
    return head;
}