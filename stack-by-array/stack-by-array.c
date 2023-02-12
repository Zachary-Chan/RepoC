#include "stack-by-array.h"
#include <stdio.h>

// simply let top equal to -1
Stack *initialize(Stack *stack)
{
    stack->top = -1;
    return stack;
}

void push(Stack *stack, DATA_TYPE value)
{
    // special case, stack is full
    if(stack->top == SIZE - 1){
        return;
    }

    // general case
    stack->top++;
    stack->stack[stack->top] = value;
}

DATA_TYPE pop(Stack *stack)
{
    // special case, stack is empty 
    if (stack->top == -1){
        return -1;
    }

    DATA_TYPE return_value = stack->stack[stack->top];
    stack->top--;
    return return_value;
}

DATA_TYPE peek(Stack *stack)
{
    // if empty 
    if(stack->top == -1){
        return -1;
    }

    return stack->stack[stack->top];
}

void displayAll(Stack *stack)
{
    // if empty 
    if (stack->top == -1){
        return;
    }

    for(int i = stack->top; i >= 0; i--) {
        printf("[%d] ", stack->stack[i]);
    }
    puts("");
}
