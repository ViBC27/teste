#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
  int value;
  node_t *previous;
  node_t *next;
};

node_t* newDoublyList();
node_t* addFront(node_t *head, int value);
node_t* addRear(node_t *tail, int value);
node_t* search(node_t *head, int value);
node_t* delete(node_t *head, int value);
int isEmpty(node_t *head);
void showListFront(node_t *head);
void showListBack(node_t *tail);
void eraseDoublyList(node_t *head);

int main() {
  node_t *L1 = newDoublyList();
  L1 = addFront(L1, 3);
  L1 = addFront(L1, 9);
  L1 = addFront(L1, 27);
  showListBack(L1);
  eraseDoublyList(L1);
  return 0;
}

node_t* newDoublyList() {
  return NULL;
}

node_t* addFront(node_t *head, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->next = head;
  newNode->previous = NULL;
  if(head != NULL) {
    head->previous = newNode;
  }
  return newNode;
}

node_t* addRear(node_t *tail, int value) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  node_t *nAux = tail;
  newNode->value = value;
  newNode->next = NULL;
  if(tail == NULL) {
    newNode->previous = NULL;
    return newNode;
  }
  while(nAux->next != NULL) {
    nAux = nAux->next;
  }
  nAux->next = newNode;
  newNode->previous = nAux;
  return tail;
}


node_t* search(node_t *head, int value) {
  while(head != NULL){
    if(head->value == value) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

int isEmpty(node_t *head) {
  return (head == NULL);
}

void showListFront(node_t *head) {
  if(head != NULL) {
    printf("%d ", head->value);
      showListFront(head->next);
  }
}

void showListBack(node_t *head) {
  if(head != NULL) {
    showListBack(head->next);
    printf("%d ", head->value);
  }
}

void eraseDoublyList(node_t *head) {
  while(head != NULL) {
    node_t *next = head->next;
    free(head);
    head = next;
  }
}
