#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H

#define SIZE 5
typedef int DATA_TYPE;
typedef struct Stack {
    int top;
    DATA_TYPE stack[SIZE];
}Stack;

Stack* initialize(Stack* stack);
void push(Stack* stack, DATA_TYPE value);
DATA_TYPE pop(Stack* stack);
DATA_TYPE peek(Stack* stack);
void displayAll(Stack* stack);

#endif