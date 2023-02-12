#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include "../linked-list/singly-linked-list.h"

typedef struct Stack {
    Node* top; // index for upper open end of the stack 
    Node* stack;
}Stack;

struct linked_stack {
    // functions:
    Stack* (*initialize)(Stack* stack);
    void (*push)(Stack* stack, DATA_TYPE value);
    DATA_TYPE (*pop)(Stack* stack);
    DATA_TYPE (*peek)(Stack* stack);
    void (*displayAll)(Stack* stack);
    Stack* (*deleteAll)(Stack* stack);
};

extern const struct linked_stack LINKED_STACK;


#endif 