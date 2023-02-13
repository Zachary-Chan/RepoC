#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include "../linked-list/singly-linked-list.h"

Node* queue;

struct linked_queue {
    // functions
    Node* (*initialize)(Node* queue);
    Node* (*insert)(Node* queue, DATA_TYPE value);
    Node* (*deleteElement)(Node* queue);
    void (*display)(Node* queue);
    DATA_TYPE (*peek)(Node* queue);
    Node* (*deleteAll)(Node* queue); 
};

extern const struct linked_queue LINKED_QUEUE;

#endif 