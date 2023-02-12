#include "linked-stack.h"
#include <stdio.h>

Stack* initializeStack(Stack* stack) {
    stack->top = NULL;
    stack->stack = initializeList();
    return stack;
}

void displayStack(Stack *stack)
{
    displayInt(stack->stack);
}

Stack *deleteStack(Stack *stack)
{
    stack->stack = deleteAll(stack->stack);
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, DATA_TYPE value) {
    stack->stack = insertEnd(stack->stack, value);
    stack->top = showEndNode(stack->stack);
}

DATA_TYPE pop(Stack* stack) {
    if (isEmpty(stack->stack)) {
        return -1;
    }

    DATA_TYPE return_value = showEndData(stack->stack);
    stack->stack = deleteEnd(stack->stack);
    stack->top = showEndNode(stack->stack);

    return return_value;
}

DATA_TYPE peek(Stack* stack) {
    if (isEmpty(stack->stack)) {
        return -1;
    }

    return showEndData(stack->stack);
}