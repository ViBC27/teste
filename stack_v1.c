#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack stack_t;
typedef struct node node_t;
struct node {
  int info;
  node_t *next;
};
struct stack {
  node_t *top;
  int size;
};

stack_t* newStack();
void eraseStack(stack_t *stack);
void push(stack_t *stack, int info);
int pop(stack_t *stack);
int peek(stack_t *stack);
int isEmpty(stack_t *stack);
void showStackFront(stack_t *stack);
void showStackBack(stack_t *stack);

int main() {
  stack_t *stack = newStack();
  push(stack, 5);
  push(stack, 15);
  push(stack, 27);
  int V1 = peek(stack);
  int V2 = peek(stack);
  showStackFront(stack);
  eraseStack(stack);
  return 0;
}

stack_t* newStack() {
  stack_t *newStack = (stack_t*) malloc(sizeof(stack_t));
  newStack->top = NULL;
  newStack->size = 0;
  return newStack;
}

void eraseStack(stack_t *stack) {
  stack->size = 0;
  while(stack->top != NULL) {
    node_t* nAux = stack->top;
    stack->top = stack->top->next;
    free(nAux);
  }
}

void push(stack_t *stack, int info) {
  node_t *newTop = (node_t*) malloc(sizeof(node_t));
  newTop->info = info;
  newTop->next = stack->top;
  stack->top = newTop;
  stack->size += 1;
}

int pop(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return INT_MIN;
  }
  else {
    node_t *nAux = stack->top;
    int info = stack->top->info;
    stack->top = stack->top->next;
    stack->size -= 1;
    free(nAux);
    return info;
  }
}

int peek(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return INT_MIN;
  }
  else {
    int info = stack->top->info;
    return info;
  }
}

int isEmpty(stack_t *stack) {
  return (stack->top == NULL) ? 1 : 0;
}

void showStackFront(stack_t *stack) {
  if(!isEmpty(stack)) {
    int info = pop(stack);
    printf("%d\n", info);
    showStackFront(stack);
  }
}

void showStackBack(stack_t *stack) {
  if(!isEmpty(stack)) {
    int info = pop(stack);
    showStackBack(stack);
    printf("%d\n", info);
  }
}
