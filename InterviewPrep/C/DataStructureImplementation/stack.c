#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Stack
{
    int size;
    int top;
    int* array;
} Stack;

Stack* initStack(int size) {
    if (size == 0) {
        return NULL;
    }
    Stack* nStack = (Stack*) malloc(sizeof(Stack));
    nStack->size = size;
    nStack->top = -1;
    nStack->array = (int*) malloc(sizeof(int)*size);
    return nStack;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return stack->top+1 == stack->size;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        // increase array 
        stack->array = (int*) realloc(stack->array, stack->size*2*sizeof(int));
        stack->size = stack->size*2;
    }
    stack->top += 1;
    stack->array[stack->top] = value;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }
    stack->top--;
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top];
}

int main() {
    Stack* stack = initStack(10);

    push(stack, 5);
    push(stack, 7);
    pop(stack);
    push(stack, 10);

    assert((stack->array)[0] == 5);

    assert(stack->array[1] == 10);
    assert(stack->size == 10);
    assert(stack->top == 1);

    assert(top(stack) == 10);

    assert(!isEmpty(stack));

    for (int i = 0; i < 8; i++) {
        push(stack, i);
    }
    assert(isFull(stack));

    push(stack, 100);

    assert(top(stack) == 100);

    while (!isEmpty(stack)) {
        pop(stack);
    }

    free(stack->array);
    free(stack);

    printf("Success\n");
    return 0;
}

