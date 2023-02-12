#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <stdbool.h>

// define suitable data type 
typedef int DATA_TYPE;
typedef struct Node{
    DATA_TYPE data;
    struct Node* next;
}Node;

// functions
bool isEmpty(Node* head);

Node* initializeList();
void displayInt(Node* head);
Node* insertBeginning(Node* head, DATA_TYPE value);
Node* insertEnd(Node* head, DATA_TYPE value);
Node* insertBefore(Node* head, DATA_TYPE value, DATA_TYPE before_value);
Node* insertAfter(Node* head, DATA_TYPE value, DATA_TYPE after_value);

Node* deleteBeginning(Node* head);
Node* deleteEnd(Node* head);
Node* deleteNode(Node* head, DATA_TYPE value);
Node* deleteBefore(Node* head, DATA_TYPE before_value);
Node* deleteAfter(Node* head, DATA_TYPE after_value);
Node* deleteAll(Node* head);

DATA_TYPE showEndData(Node* head);
Node* showEndNode(Node* head);

#endif