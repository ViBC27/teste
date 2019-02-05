#include <stdio.h>
#include <stdlib.h>

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

stack_t* newStack() {
  stack_t *newStack = (stack_t*) malloc(sizeof(stack_t));
  newStack->top = NULL;
  newStack->size = 0;
  return newStack;
}

void eraseStack(stack_t *stack) {
  node_t* nAux1 = stack->top;
  stack = NULL;
  while(nAux1 != NULL) {
    node_t* nAux2 = nAux1->next;
    free(nAux1);
    nAux1 = nAux2;
  }
}

int isEmpty(stack_t *stack) {
  return (stack->top == NULL) ? 1 : 0;
}

void push(stack_t *stack, int info) {
  node_t *newTop = (node_t*) malloc(sizeof(node_t));
  newTop->info = info;
  newTop->next = stack->top;
  stack->top = newTop;
  stack->size += 1;
}

node_t* pop(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return NULL;
  }
  else {
    node_t *nAux = stack->top;
    stack->top = stack->top->next;
    //nAux->next = NULL;
    stack->size -= 1;
    return nAux;
  }
}

node_t* peek(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  else {
    node_t *nAux = stack->top;
    //nAux->next = NULL;
    return nAux;
  }
}

void showStackFront(stack_t *stack) {
  if(!isEmpty(stack)) {
    node_t *nAux = pop(stack);
    printf("%d\n", nAux->info);
    showStackFront(stack);
  }
}

void showStackBack(stack_t *stack) {
  if(!isEmpty(stack)) {
    node_t *nAux = pop(stack);
    showStackBack(stack);
    printf("%d\n", nAux->info);
  }
}

int main() {
  stack_t *stack = newStack();
  push(stack, 5);
  push(stack, 15);
  node_t *aux1 = pop(stack);
  node_t *aux2 = pop(stack);
  node_t *aux3 = peek(stack);
  node_t *aux4 = peek(stack);
  push(stack, 27);
  showStackFront(stack);
  eraseStack(stack);
  return 0;
}
