#include "linked-stack.h"
#include <stdio.h>

static Stack* initialize(Stack* stack) {
    stack->top = NULL;
    stack->stack = SINGLY_LINKED_LIST.initialize();
    return stack;
}

static void displayAll(Stack *stack)
{
    SINGLY_LINKED_LIST.displayAll(stack->stack);
}

static Stack *deleteAll(Stack *stack)
{
    stack->stack = SINGLY_LINKED_LIST.deleteAll(stack->stack);
    stack->top = NULL;
    return stack;
}

static void push(Stack* stack, DATA_TYPE value) {
    stack->stack = SINGLY_LINKED_LIST.insertBeginning(stack->stack, value);
    stack->top = stack->stack;
}

static DATA_TYPE pop(Stack* stack) {
    if (SINGLY_LINKED_LIST.isEmpty(stack->stack)) {
        return -1;
    }

    DATA_TYPE return_value = SINGLY_LINKED_LIST.showBeginningData(stack->stack);
    stack->top = stack->stack->next;
    stack->stack = SINGLY_LINKED_LIST.deleteBeginning(stack->stack);
    return return_value;
}

static DATA_TYPE peek(Stack* stack) {
    if (SINGLY_LINKED_LIST.isEmpty(stack->stack)) {
        return -1;
    }

    return SINGLY_LINKED_LIST.showBeginningData(stack->stack);
}

const struct linked_stack LINKED_STACK = {
    .initialize = initialize,
    .push = push,
    .pop = pop,
    .peek = peek,
    .displayAll = displayAll,
    .deleteAll = deleteAll
};