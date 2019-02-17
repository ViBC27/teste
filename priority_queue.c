#include <stdio.h>
#include <stdlib.h>

typedef struct queue queue_t;
typedef struct node node_t;
struct node {
  int info;
  int priority;
  node_t *next;
};
struct queue {
  node_t *head;
};

queue_t* newQueue() {
  queue_t *newQueue = (queue_t*) malloc(sizeof(queue_t));
  newQueue->head = NULL;
  return newQueue;
}

void eraseQueue(queue_t *queue) {
  node_t* nAux1 = queue->head;
  free(queue); queue = NULL;
  while(nAux1 != NULL) {
    node_t* nAux2 = nAux1->next;
    free(nAux1);
    nAux1 = nAux2;
  }
}

int isEmpty(queue_t *queue) {
  return (queue->head == NULL) ? 1 : 0;
}

int maximum(queue_t *queue) {
  if(isEmpty(queue)) {
    printf("Priority Queue Underflow\n");
    return -1;
  }
  return queue->head->priority;
}

node_t* addNode(int info, int priority) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->priority = priority;
  newNode->info = info;
  newNode->next = NULL;
  return newNode;
}

void enqueue(queue_t *queue, int info, int priority) {
  node_t *newNode = addNode(info, priority);
  if(isEmpty(queue) || priority > queue->head->priority) {
    newNode->next = queue->head;
    queue->head = newNode;
  }
  else {
    node_t *nAux = queue->head;
    while(nAux->next != NULL && nAux->priority > priority) {
      nAux = nAux->next;
    }
    newNode->next = nAux->next;
    nAux->next = newNode;
  }
}

node_t* dequeue(queue_t *queue) {
  if(isEmpty(queue)) {
    printf("Priority Queue Underflow\n");
    return NULL;
  }
  else {
    node_t *nAux = queue->head;
    queue->head = queue->head->next;
    nAux->next = NULL;
    return nAux;
  }
}

void showQueue(queue_t *queue) {
  node_t *nAux;
  while(!isEmpty(queue)) {
    nAux = dequeue(queue);
    printf("Priority: %d | ", nAux->priority);
    printf("Info: %d\n", nAux->info); 
  }
}

int main() {
  queue_t *queue = newQueue();
  enqueue(queue, 30, 254);
  enqueue(queue, 40, 700);
  enqueue(queue, 10, 100);
  enqueue(queue, 20, 300);
  showQueue(queue);
  eraseQueue(queue);
  return 0;
}
