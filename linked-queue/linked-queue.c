#include "linked-queue.h"

static Node* initialize(Node* queue) {
    return SINGLY_LINKED_LIST.initialize(queue);
}

static Node* insert(Node* queue, DATA_TYPE value) {
    return SINGLY_LINKED_LIST.insertEnd(queue, value);
}

static Node* deleteElement(Node* queue) {
    if (SINGLY_LINKED_LIST.isEmpty(queue) ) {
        return queue;
    }
    return SINGLY_LINKED_LIST.deleteBeginning(queue);
}

static void display(Node* queue) {
    SINGLY_LINKED_LIST.displayAll(queue);
}

static DATA_TYPE peek(Node* queue) {
    return SINGLY_LINKED_LIST.showBeginningData(queue);
}

static Node* deleteAll(Node* queue) {
    return SINGLY_LINKED_LIST.deleteAll(queue);
}

const struct linked_queue LINKED_QUEUE = {
    .initialize = initialize,
    .insert = insert,
    .deleteElement = deleteElement,
    .display = display,
    .peek = peek,
    .deleteAll = deleteAll
};