#include <stdio.h>
#include <stdlib.h>

typedef struct data data_t;
typedef struct stack stack_t;
typedef struct node node_t;

struct data {
  int info;
  int age;
};
struct node {
  data_t data;
  node_t *next;
};
struct stack {
  node_t *top;
  int size;
};

data_t error() {
  data_t data;
  data.info = -1;
  data.age = -1;
  return data;
}

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

void push(stack_t *stack, data_t data) {
  node_t *newTop = (node_t*) malloc(sizeof(node_t));
  newTop->data = data;
  newTop->next = stack->top;
  stack->top = newTop;
  stack->size += 1;
}

data_t pop(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return error();
  }
  else {
    node_t *nAux = stack->top;
    data_t data = stack->top->data;
    stack->top = stack->top->next;
    stack->size -= 1;
    free(nAux);
    return data;
  }
}

data_t peek(stack_t *stack) {
  if(isEmpty(stack)) {
    printf("Stack Underflow\n");
    return error();
  }
  else {
    data_t data = stack->top->data;
    return data;
  }
}

void echoMyData(data_t data){
  printf("Info: %d, Age: %d\n", data.info, data.age);
}

void showStackFront(stack_t *stack) {
  if(!isEmpty(stack)) {
    data_t data = pop(stack);
    echoMyData(data);
    showStackFront(stack);
  }
}

void showStackBack(stack_t *stack) {
  if(!isEmpty(stack)) {
    data_t data = pop(stack);
    showStackBack(stack);
    echoMyData(data);
  }
}

int main() {
  stack_t *stack = newStack();

  data_t data;
  data.info = 27;
  data.age = 10;

  push(stack, data);
  data = pop(stack);
  data = pop(stack);
  showStackFront(stack);
  eraseStack(stack);

  return 0;
}
