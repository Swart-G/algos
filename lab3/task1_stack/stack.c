#include "stack.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create(void) {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->top = NULL;
    return stack;
}

int stack_push(Stack *stack, int value) {
    if (stack == NULL) {
        return -EINVAL;
    }

    StackNode *newNode = malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return -ENOMEM;
    }

    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return 0;
}

int stack_pop(Stack *stack, int *value) {
    if (stack == NULL) {
        return -EINVAL;
    }
    if (stack->top == NULL) {
        return -ENOENT;
    }

    StackNode *old_top = stack->top;

    if (value != NULL) {
        *value = stack->top->value;
    }
    stack->top = stack->top->next;
    free(old_top);
    return 0;
}

int stack_is_empty(Stack *stack) {
    if (stack == NULL) {
        return -EINVAL;
    }
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}

int stack_destroy(Stack *stack) {
    if (stack == NULL) {
        return -EINVAL;
    }

    while (stack_is_empty(stack) == 0) {
        stack_pop(stack, NULL);
    }
    free(stack);
    return 0;
}

int stack_print(Stack *stack) {
    if (stack == NULL) {
        return -EINVAL;
    }
    if (stack_is_empty(stack) == 1) {
        return -ENOENT;
    }

    StackNode *currentNode = stack->top;
    printf("Элементы стека:\n");
    while (currentNode != NULL) {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    }
    return 0;
}