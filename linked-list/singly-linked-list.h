#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <stdbool.h>

typedef int DATA_TYPE;
typedef struct Node{
    DATA_TYPE data;
    struct Node* next;
}Node;

struct singly_linked_list {
    // functions
    bool (*isEmpty)(Node* head);

    Node* (*initialize)();
    void (*displayAll)(Node* head);
    Node* (*insertBeginning)(Node* head, DATA_TYPE value);
    Node* (*insertEnd)(Node* head, DATA_TYPE value);
    Node* (*insertBefore)(Node* head, DATA_TYPE value, DATA_TYPE before_value);
    Node* (*insertAfter)(Node* head, DATA_TYPE value, DATA_TYPE after_value);

    Node* (*deleteBeginning)(Node* head);
    Node* (*deleteEnd)(Node* head);
    Node* (*deleteNode)(Node* head, DATA_TYPE value);
    Node* (*deleteBefore)(Node* head, DATA_TYPE before_value);
    Node* (*deleteAfter)(Node* head, DATA_TYPE after_value);
    Node* (*deleteAll)(Node* head);

    DATA_TYPE (*showEndData)(Node* head);
    Node* (*showEndNode)(Node* head);
};

extern const struct singly_linked_list SINGLY_LINKED_LIST;

#endif