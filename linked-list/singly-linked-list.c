#include "singly-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

bool isEmpty(Node* head) {
    if(!head) {
        return true;
    }
    return false;
}

// initialize linked list, making head equal to NULL
Node *initialize()
{
    Node* head = NULL;
    return head;
}

// display all linked list data, assuming DATA_TYPE is int
void displayInt(Node *head)
{
    while (head){
        printf("%d \t", head->data);
    }
    puts("");
}

Node *insertBeginning(Node *head, DATA_TYPE value)
{
    // first step, creating new_node Node structure
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;

    // second step, put new_node at beginning 
    // special case, if the list is empty
    if (!head ) {
        new_node->next = NULL;
        head = new_node;
        return head;
    }

    // general situation
    new_node->next = head;
    head = new_node;
    return head;
}

Node *insertEnd(Node *head, DATA_TYPE value)
{
    //first step, creating new_node containing the value 
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;

    // second step, connecting linked list 
    // Special case, list is empty !head 
    if (!head) {
        new_node->next = NULL;
        head = new_node;
        return head;
    }

    // general case
    // loop ptr until ptr->next == NULL
    Node* ptr = head;
    while(ptr->next) {  ptr = ptr->next; }
    ptr->next = new_node;
    new_node->next = NULL;

    return head;
}

// insert before the first value found, and assume that the before_value indeed exists(list is not empty)
Node *insertBefore(Node *head, DATA_TYPE value, DATA_TYPE before_value)
{
    // first step, creating new_node containing the value
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;

    // second step, connecting linked list 
    // special case, first node is before_value
    if(head->data == before_value) {
        head = insertBeginning(head, value);
        return head;
    }

    // general case
    Node* ptr = head;
    while (ptr->next->data != before_value) {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

// insert after the first found value, assume that after_value indeed exists(list is not empty)
Node *insertAfter(Node *head, DATA_TYPE value, DATA_TYPE after_value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;

    Node* ptr = head;
    while(ptr->data != after_value) {
        ptr = ptr->next;
    }

    // special case, after_value is the last node
    if(!ptr->next ) {
        head = insertEnd(head, value);
        return head;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    return head;
}

// assume list is not empty 
Node *deleteBeginning(Node *head)
{
    // special case, only one node in list 
    if(!head->next) {
        free(head);
        head = NULL;
        return head;
    }

    // general case 
    Node* ptr = head->next;
    free(head);
    head = ptr;
    return head;
}

Node *deleteEnd(Node *head)
{
    // special case, only one node in list
    if (!head->next) {
        free(head);
        head = NULL;
        return head;
    }

    // general case
    Node* ptr = head;
    while(ptr->next->next) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

// Assume list is not empty and value exists 
Node *deleteNode(Node *head, DATA_TYPE value)
{
    // special case, value is the first node
    if (head->data == value) {
        head = deleteBeginning(head);
        return head;
    }

    Node* ptr = head;
    while (ptr->next->data != value ) {
        ptr = ptr->next;
    }

    // special case, value is the last node
    if(!ptr->next->next ) {
        head = deleteEnd(head);
        return head;
    }

    // general case
    Node* temp = ptr->next->next;
    free(ptr->next);
    ptr->next = temp;
    return head;
}

// delete the node before firstly found node with data equal to before_value
Node *deleteBefore(Node *head, DATA_TYPE before_value)
{
    // special case, before_value is the first node, do nothing 
    if(head->data == before_value) {
        return head;
    }

    // general case
    Node* ptr = head;
    while (ptr->next->data != before_value) {
        ptr = ptr->next;
    }
    // assume no duplicate values 
    head = deleteNode(head, ptr->data);
    return head;
}

// delete the node after firstly found node with data equal to after_value
Node *deleteAfter(Node *head, DATA_TYPE after_value)
{
    Node* ptr = head;
    while (ptr->data != after_value) {
        ptr = ptr->next;
    }

    // special case, after_value is the last node, do nothing 
    if(!ptr->next) {
        return head;
    }

    // assume no duplicate values 
    head = deleteNode(head, ptr->next->data);
    return head;
}

Node *deleteAll(Node *head)
{
    Node* ptr = head;
    while (ptr) {
        head = deleteNode(head, ptr->data);
        ptr = ptr->next;
    }
    return head;
}
