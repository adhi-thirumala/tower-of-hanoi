#include "stack.h"

#include <stdlib.h>

Stack *create_stack(int capacity) {
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

int is_empty(Stack *stack) { return stack->top == -1; }

int is_full(Stack *stack) { return stack->top == stack->capacity - 1; }

int size(Stack *stack) { return stack->top + 1; }


void free_stack(Stack *stack) {
  free(stack->data);
  free(stack);
}
