#include "queue-by-array.h"
#include <stdio.h>

static int front, rear;

// simply make front and rear equal to -1
static void initialize(DATA_TYPE* queue) {
    front = rear = -1;
}

static void insert(DATA_TYPE* queue, DATA_TYPE value) {
    // empty
    if (front == -1 && rear == -1) {
        queue[0] = value;
        front = rear = 0;
        return;
    }

    // full
    if(rear == SIZE - 1){
        return;
    }

    rear++;
    queue[rear] = value;
}

static void reset(DATA_TYPE* queue) {
    initialize(queue);
}

static DATA_TYPE deleteElement(DATA_TYPE* queue) {
    if(front == -1 && rear == -1) {
        return -1;
    }

    DATA_TYPE return_value = queue[front];
    front++;

    // becomes empty queue
    if(front > rear) {
        reset(queue);
    }
    return return_value;
}

static DATA_TYPE peek(DATA_TYPE* queue) {
    // empty
    if (front == -1 && rear == -1){
        return -1;
    }
    return queue[front];
}

static void display(DATA_TYPE* queue) {
    int local_front = front;
    int local_rear = rear;
    if(local_front == -1 && local_rear == -1) {
        return;
    }

    while (local_front <= local_rear) {
        printf("[%d] ", queue[local_front]);
        local_front++;
    }
    puts("");
}

const struct queue_by_array QUEUE_BY_ARRAY = {
    .initialize = initialize,
    .insert = insert,
    .deleteElement = deleteElement,
    .peek = peek,
    .display = display,
    .reset = reset
};