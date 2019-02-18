#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
typedef struct queue queue_t;
struct queue {
  int currentSize;
  int head;
  int tail;
  int items[SIZE];
};

queue_t* newQueue() {
  queue_t *newQueue = (queue_t*) malloc(sizeof(queue_t));
  newQueue->currentSize = 0;
  newQueue->head = 0;
  newQueue->tail = SIZE - 1;
  return newQueue;
}

int isEmpty(queue_t *queue) {
    return (queue->currentSize == 0) ? 1 : 0;
}

void enqueue(queue_t *queue, int item) {
  if(queue->currentSize == SIZE) {
    printf("Queue overflow\n");
  }
  else {
    queue->tail = (queue->tail + 1) % SIZE;
    queue->items[queue->tail] = item;
    queue->currentSize++;
  }
}

int dequeue(queue_t *queue) {
  if(isEmpty(queue)) {
    printf("Queue Underflow\n");
    return -1;
  }
  else {
    int dequeue = queue->items[queue->head];
    queue->head = (queue->head + 1) % SIZE;
    queue->currentSize--;
    return dequeue;
  }
}

int main() {
  queue_t *Q1 = newQueue();
  enqueue(Q1, 10);
  enqueue(Q1, 20);
  enqueue(Q1, 30);
  enqueue(Q1, 40);
  enqueue(Q1, 50);
  enqueue(Q1, 60);
  int V1 = dequeue(Q1);
  int V2 = dequeue(Q1);
  int V3 = dequeue(Q1);
  printf("%d\n%d\n%d\n", V1, V2, V3);
  return 0;
}
