#ifndef ALGOS_STACK_H
#define ALGOS_STACK_H

typedef struct StackNode {
    int value;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

Stack *stack_create(void);
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *value);
int stack_is_empty(Stack *stack);
int stack_destroy(Stack *stack);
int stack_print(Stack *stack);

#endif // ALGOS_STACK_H
