#include <stdio.h>
#include <assert.h>
#include "queue.h"

int main() {
    queue q;

    // Initialize the queue
    initialize(&q);

    // Test: Queue must be empty after initialization
    assert(empty(&q));

    // Test: Enqueue and dequeue a single element
    enqueue(&q, 42);
    int y = dequeue(&q);
    assert(empty(&q));
    assert(y == 42);

    // Test: Enqueue two elements and dequeue them in order
    enqueue(&q, 10);
    enqueue(&q, 20);
    int y0 = dequeue(&q);
    int y1 = dequeue(&q);
    assert(empty(&q));
    assert(y0 == 10);
    assert(y1 == 20);

    printf("All tests passed!\n");
    return 0;
}

