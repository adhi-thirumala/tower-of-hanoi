#ifndef STACK_H
#define STACK_H


typedef struct stack {
  int *data;
  int top;
  int capacity;
} Stack;

Stack* createstack(int capacity);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);

#endif
