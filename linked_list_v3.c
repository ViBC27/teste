#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
typedef struct list list_t;
struct node {
  node_t *next;
  int value;
};
struct list {
  node_t *front;
  node_t *rear;
  int size;
};

list_t* new_List();
void erase_List(list_t *list);
void addFront_List(list_t *list, int value);
void addRear_List(list_t *list, int value);
int isEmpty_List(list_t *list);
int size_List(list_t *list);
void showFront_List(list_t *list);

int main() {
  list_t *L1 = new_List();
  addRear_List(L1, 10);
  addRear_List(L1, 30);
  addRear_List(L1, 40);
  addRear_List(L1, 20);
  showFront_List(L1);
  printf("Size: %d\n", size_List(L1));
  erase_List(L1);
  free(L1);
  return 0;
}

list_t* new_List() {
  list_t *newList = (list_t*) malloc(sizeof(list_t));
  newList->front = newList->rear = NULL;
  newList->size = 0;
  return newList;
}

void erase_List(list_t *list) {
  list->rear = NULL;
  list->size = 0;
  while(list->front != NULL) {
    node_t *nAux = list->front;
    list->front = list->front->next;
    free(nAux);
  }
}

void addFront_List(list_t *list, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  list->size += 1;
  if(list->front == NULL) {
    list->front = list->rear = newNode;
  }
  else {
    newNode->next = list->front;
    list->front = newNode;
  }  
}

void addRear_List(list_t *list, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  list->size += 1;
  if(list->rear == NULL) {
    list->rear = list->front = newNode;
  }
  else {
    list->rear->next = newNode;
    list->rear = newNode;
  }
}

int isEmpty_List(list_t *list) {
  return (list->front == NULL);
}

int size_List(list_t *list) {
  return list->size;
}

void showFront(node_t *head) {
  if(head->next != NULL) {
    printf("%d ", head->value);
    showFront(head->next);
  }
  else {
    printf("%d\n", head->value);
  }
}

void showFront_List(list_t *list) {
  if(isEmpty_List(list)) {
    printf("List Underflow\n");
  }
  else {
    showFront(list->front);
  }
}
