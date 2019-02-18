#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node node_t;
typedef struct deque deque_t;
struct node {
  node_t *previous;
  node_t *next;
  int value;
};
struct deque {
  node_t *front;
  node_t *rear;
  int size;
};

deque_t* new_Deque();
void delete_Deque(deque_t *deque);
void erase_Deque(deque_t *deque);
void enqueueFront_Deque(deque_t *deque, int value);
void enqueueRear_Deque(deque_t *deque, int value);
int dequeueFront_Deque(deque_t *deque);
int dequeueRear_Deque(deque_t *deque);
int front_Deque(deque_t *deque);
int rear_Deque(deque_t *deque);
int isEmpty_Deque(deque_t *deque);
int size_Deque(deque_t *deque);
void showFront_Deque(deque_t *deque);
void showBack_Deque(deque_t *deque);

int main() {
  deque_t *D1 = new_Deque();
  enqueueFront_Deque(D1, 10);
  enqueueRear_Deque(D1, 30);
  showFront_Deque(D1);
  showBack_Deque(D1);
  printf("Front: %d\n", front_Deque(D1));
  printf("Rear: %d\n", rear_Deque(D1));
  printf("Size: %d\n", size_Deque(D1));
  erase_Deque(D1);
  return 0;
}

deque_t* new_Deque() {
  deque_t *newDeque = (deque_t*) malloc(sizeof(deque_t));
  newDeque->front = newDeque->rear = NULL;
  newDeque->size = 0;
  return newDeque;
}

void delete_Deque(deque_t *deque) {
  erase_Deque(deque);
  free(deque);
}

void erase_Deque(deque_t *deque) {
  deque->rear = NULL;
  deque->size = 0;
  while(deque->front != NULL) {
    node_t *nAux = deque->front;
    deque->front = deque->front->next;
    free(nAux);
  }
}

void enqueueFront_Deque(deque_t *deque, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->previous = newNode->next = NULL;
  newNode->value = value;
  deque->size += 1;
  if(deque->front == NULL) {
    deque->front = deque->rear = newNode;
  }
  else {
    newNode->next = deque->front;
    deque->front->previous = newNode;
    deque->front = newNode;
  }  
}

void enqueueRear_Deque(deque_t *deque, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->previous = newNode->next = NULL;
  newNode->value = value;
  deque->size += 1;
  if(deque->rear == NULL) {
    deque->rear = deque->front = newNode;
  }
  else {
    newNode->previous = deque->rear;
    deque->rear->next = newNode;
    deque->rear = newNode;
  }
}

int dequeueFront_Deque(deque_t *deque) {
  if(isEmpty_Deque(deque)) {
    printf("Deque Underflow\n");
    return INT_MIN;
  }
  else {
    node_t *nAux = deque->front;
    int value = deque->front->value;
    deque->front = deque->front->next;
    deque->size -= 1;
    if(deque->front == NULL) {
      deque->rear = NULL;
    }
    else {
      deque->front->previous = NULL;
    }
    free(nAux);
    return value;
  }
}

int dequeueRear_Deque(deque_t *deque) {
  if(isEmpty_Deque(deque)) {
    printf("Deque Underflow\n");
    return INT_MIN;
  }
  else {
    node_t *nAux = deque->rear;
    int value = deque->rear->value;
    deque->rear = deque->rear->previous;
    deque->size -= 1;
    if(deque->rear == NULL) {
      deque->front = NULL;
    }
    else {
      deque->rear->next = NULL;
    }
    free(nAux);
    return value;
  }
}

int front_Deque(deque_t *deque) {
  if(isEmpty_Deque(deque)) {
    printf("Deque Underflow\n");
    return INT_MIN;
  }
  else {
    return deque->front->value;
  }
}

int rear_Deque(deque_t *deque) {
  if(isEmpty_Deque(deque)) {
    printf("Deque Underflow\n");
    return INT_MIN;
  }
  else {
    return deque->rear->value;
  }
}

int isEmpty_Deque(deque_t *deque) {
  return (deque->front == NULL);
}

int size_Deque(deque_t *deque) {
  return deque->size;
}

void showFront_Deque(deque_t *deque) {
  if(isEmpty_Deque(deque)) {
    printf("Deque Underflow\n");
  }
  else {
    node_t *nAux = deque->front;
    while(nAux->next != NULL) {
      printf("%d ", nAux->value);
      nAux = nAux->next;
    }
    printf("%d\n", nAux->value);
  }
}

void showBack_Deque(deque_t *deque) {
  if(isEmpty_Deque(deque)) {
    printf("Deque Underflow\n");
  }
  else {
    node_t *nAux = deque->rear;
    while(nAux->previous != NULL) {
      printf("%d ", nAux->value);
      nAux = nAux->previous;
    }
    printf("%d\n", nAux->value);
  }
}