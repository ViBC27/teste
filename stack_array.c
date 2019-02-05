#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

typedef struct stack stack_t;
struct stack {
  int currentSize;
  int items[STACK_SIZE];
};

stack_t* newStack() {
  stack_t *newStack = (stack_t*) malloc(sizeof(stack_t));
  newStack->currentSize = 0;
  return newStack;
}

int isEmpty(stack_t *stack) {
  return (stack->currentSize == 0) ? 1 : 0;
}

int isFull(stack_t *stack) {
  return (stack->currentSize == STACK_SIZE) ? 1 : 0;
}

void push(stack_t *stack, int item) {
  if(isFull(stack)) {
    printf("Stack Overflow\n");
  }
  else {
    stack->items[stack->currentSize++] = item;
  }
}

int pop(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  else {
    return stack->items[--stack->currentSize];
  }
}

int peek(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  else {
    return stack->items[stack->currentSize - 1];
  }
}

int main() {
  stack_t *stack = newStack();
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);
  push(stack, 60);
  push(stack, 70);
  push(stack, 80);
  push(stack, 90);
  push(stack, 100);
  push(stack, 110);
  return 0;
}
