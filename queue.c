#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
typedef struct queue queue_t;
struct queue {
  node_t *head;
  node_t *tail;
};
struct node {
  int value;
  node_t *next;
};

queue_t* newQueue() {
  queue_t *newQueue = (queue_t*) malloc(sizeof(queue_t));
  newQueue->head = newQueue->tail = NULL;
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

node_t* addNode(int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void enqueue(queue_t *queue, int value) {
  node_t *newNode = addNode(value);
  if(queue->tail == NULL) {
    queue->head = queue->tail = newNode;
  }
  else {
    queue->tail->next = newNode;
    queue->tail = newNode;
  }
}

int dequeue(queue_t *queue) {
  if(queue->head == NULL) {
    printf("Queue Underflow\n");
    return -1;
  }
  else {
    node_t *nAux = queue->head;
    int value = queue->head->value;
    queue->head = queue->head->next;
    free(nAux);
    if(queue->head == NULL) {
      queue->tail = NULL;
    }
    return value;
  }
}

int main() {
  queue_t *queue = newQueue();
  enqueue(queue, 10);
  int V1 = dequeue(queue);
  printf("%d\n", V1);
  int V2 = dequeue(queue);
  printf("%d\n", V2);
  eraseQueue(queue);
  return 0; 
} 