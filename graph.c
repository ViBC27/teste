#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct graph graph_t;
typedef struct adjList adjList_t;
typedef struct node node_t;
typedef struct queue queue_t;
struct graph {
  adjList_t *vertices[MAX_SIZE];
  short visited[MAX_SIZE];
};
struct adjList {
  int item;
  adjList_t *next;
};
struct queue {
  node_t *head;
  node_t *tail;
};
struct node {
  int value;
  node_t *next;
};

graph_t* newGraph();
adjList_t* newAdjList(int item);
void addEdge(graph_t *graph, int vertex1, int vertex2);
void dfs(graph_t *graph, int source);
void bfs(graph_t *graph, int source);
void showgraph(graph_t *graph);

queue_t* newQueue();
void eraseQueue(queue_t *queue);
node_t* addNode(int value);
int isEmpty(queue_t *queue);
void enqueue(queue_t *queue, int value);
int dequeue(queue_t *queue);

int main(void) {
  graph_t *undGraph = newGraph();
  addEdge(undGraph, 1, 2);
  addEdge(undGraph, 1, 5);
  addEdge(undGraph, 2, 5);
  addEdge(undGraph, 2, 3);
  addEdge(undGraph, 2, 4);
  addEdge(undGraph, 3, 4);
  addEdge(undGraph, 4, 5);
  bfs(undGraph, 1);
  //dfs(undGraph, 1);
  return 0;
}

graph_t* newGraph() {
  graph_t *graph = (graph_t*) malloc(sizeof(graph_t));
  int i;
  for (i = 1; i <= MAX_SIZE - 1; i++) {
    graph->vertices[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(graph_t *graph, int vertex1, int vertex2) 
{
  adjList_t *vertex = newAdjList(vertex2);
  vertex->next = graph->vertices[vertex1];
  graph->vertices[vertex1] = vertex;
  //Undirected graph. Edge to the other direction as well.
  vertex = newAdjList(vertex1);
  vertex->next = graph->vertices[vertex2];
  graph->vertices[vertex2] = vertex;
}

adjList_t* newAdjList(int item) {
  adjList_t *newAdjList = (adjList_t*) malloc(sizeof(adjList_t));
  newAdjList->item = item;
  newAdjList->next = NULL;
  return newAdjList;
}

void dfs(graph_t *graph, int source) {
  graph->visited[source] = 1;
  printf("%d\n", source);
  adjList_t *newAdjList = graph->vertices[source];
  while(newAdjList != NULL) {
    if(!graph->visited[newAdjList->item]) {
    dfs(graph, newAdjList->item);
    }
    newAdjList = newAdjList->next;
  }
}

void bfs(graph_t *graph, int source) {
  queue_t *queue = newQueue();
  int dequeued;
  adjList_t * newAdjList = graph->vertices[source];
  graph->visited[source] = 1;
  enqueue(queue, source);
  while(!isEmpty(queue)) {
    dequeued = dequeue(queue);
    newAdjList = graph->vertices[dequeued];
    while(newAdjList != NULL) {
      if(!graph->visited[newAdjList->item]) {
        printf("%d\n", newAdjList->item);
        graph->visited[newAdjList->item] = 1;
        enqueue(queue, newAdjList->item);
      }
      newAdjList = newAdjList->next;
    }
  }
}

queue_t* newQueue() {
  queue_t *newQueue = (queue_t*) malloc(sizeof(queue_t));
  newQueue->head = newQueue->tail = NULL;
  return newQueue;
}

node_t* addNode(int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

int isEmpty(queue_t *queue) {
  return (queue->head == NULL) ? 1 : 0;
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