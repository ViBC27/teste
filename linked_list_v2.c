#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
  void* info;
  node_t *next;
};

node_t* newList() {
  return NULL;
}

void eraseList(node_t *head) {
  node_t* nAux1 = head;
  while(nAux1 != NULL) {
    node_t* nAux2 = nAux1->next;
    free(nAux1);
    nAux1 = nAux2;
  }
}

node_t* addNodeFront(node_t *head, void *info) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->info = info;
  newNode->next = head;
  return newNode;
}

node_t* addNodeBack(node_t *head, void *info) {
  node_t *newNode, *nAux;
  newNode = (node_t*) malloc(sizeof(node_t));
  newNode->info = info;
  newNode->next = NULL;
  if(head == NULL) {
    head = newNode;
  }
  else {
    nAux = head;
    while(nAux->next != NULL) 
    { nAux = nAux->next; }
    nAux->next = newNode;
  }
  return head;
}

node_t* removeNode(node_t *head, void *info) {
  if(head != NULL) {
    if(head->info == info) {
      node_t *nAux = head;
      head = head->next;
      free(nAux);
    }
    else {
      head->next = removeNode(head->next, info);
    }
  }
  return head;
}

node_t* searchNode(node_t *head, void *info) {
  if(head != NULL) {
    if(head->info = info) { return head; }
    else { searchNode(head->next, info); }
  }
  else { 
    return NULL;
  }
}

int sizeList(node_t *head, int size) {
  if(head != NULL) {
    sizeList(head->next, size + 1);
  }
  else {
    return size;
  }
}

node_t* bubbleList(node_t *head, int size) {
  node_t *t, *p;
  for(t = head; t != NULL; t = t->next) {
    for(p = head; p != NULL; p = p->next) {
      if(t->info < p->info) {
        void *v = t->info;
        t->info = p->info;
        p->info = v;
      }
    }
  }
  return head;
}

int equalList(node_t *head1, node_t *head2) {
  if(head1 == NULL && head2 == NULL) {
    return 1;
  }
  else if(head1 == NULL || head2 == NULL) {
    return 0;
  }
  else {
    return (head1->info == head2->info) && 
      equalList(head1->next, head2->next);
  }
}

void showListFront(node_t *head) {
  if(head != NULL) {
    printf("%d\n", head->info);
    showListFront(head->next);
  }
}

void showListBack(node_t *head) {
  if(head != NULL) {
    showListBack(head->next);
    printf("%d\n", head->info);
  }
}

int main() {
  node_t *myList = newList();
  myList = addNodeBack(myList, (void*)10);
  myList = addNodeBack(myList, (void*)20);
  myList = addNodeBack(myList, (void*)20);
  myList = addNodeBack(myList, (void*)20);
  myList = addNodeBack(myList, (void*)30);
  myList = removeNode(myList, (void*)20);
  showListFront(myList);
  eraseList(myList);
  return 0;
}