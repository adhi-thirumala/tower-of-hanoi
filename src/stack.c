#include "stack.h"

#include <stdlib.h>

Stack *createstack(int capacity) {
Stack *stack = malloc(sizeof(Stack));
stack->capacity = capacity;
stack->top = -1;
stack->data = malloc(stack->capacity * sizeof(int));
return stack;
}

void push(Stack *stack, int item) { stack->data[++stack->top] = item; }

int pop(Stack *stack) {
  if (stack->top == -1) {
    return -1;
  }
  return stack->data[stack->top--];
}

int peek(Stack *stack) { return stack->data[stack->top]; }

int isEmpty(Stack *stack) { return stack->top == -1; }

int isFull(Stack *stack) { return stack->top == stack->capacity - 1; }
