#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

typedef struct hashTable hash_t;
typedef struct node node_t;
typedef struct list list_t;

struct hashTable {
  list_t *table[MAX_SIZE];
};
struct node {
  node_t *next;
  int value;
  int key;
};
struct list {
  node_t *front;
  node_t *rear;
  int size;
};

// Hash
hash_t* new_Hash();
void erase_Hash(hash_t *hash);
void put_Hash(hash_t *hash, int key, int value);
int get_Hash(hash_t *hash, int key);
void remove_Hash(hash_t *hash, int key);
int containsKey_Hash(hash_t *hash, int key);
void show_Hash(hash_t *hash);

// List
list_t* new_List();
void erase_List(list_t *list);
void addRear_List(list_t *list, int value, int key);
int search_List(list_t *list, int key);
void showFront_List(list_t *list);

int main() {
  hash_t *H1 = new_Hash();
  put_Hash(H1, 3, 1000);
  put_Hash(H1, 3, 27);
  put_Hash(H1, 3, 41);
  put_Hash(H1, 14, 2000);
  put_Hash(H1, 15, 3000);
  put_Hash(H1, 15, 97);
  put_Hash(H1, 92, 4000);
  //remove_Hash(H1, 15);
  show_Hash(H1);
  //printf("%d\n", containsKey_Hash(H1, 10));
  erase_Hash(H1);
  free(H1);
  return 0;
}

// Hash
hash_t* new_Hash() {
  hash_t *newHash = (hash_t*) malloc(sizeof(hash_t));
  int i;
  for(i = 0; i < MAX_SIZE; i++) {
    newHash->table[i] = NULL;
  }
  return newHash;
}

void erase_Hash(hash_t *hash) {
  int i;
  for(i = 0; i < MAX_SIZE; i++) {
    if(hash->table[i] != NULL) {
      erase_List(hash->table[i]);
      hash->table[i] = NULL;
    }
  }
}
void put_Hash(hash_t *hash, int key, int value) {
  int h = key % MAX_SIZE;
  if(hash->table[h] == NULL) {
    hash->table[h] = new_List();
  }
  addRear_List(hash->table[h], value, key);
}

int get_Hash(hash_t *hash, int key) {
  int h = key % MAX_SIZE;
  if(hash->table[h] == NULL) {
    printf("Key nonexistent.\n");
    return INT_MIN;
  }
  else {
    return search_List(hash->table[h], key);
  }
}

void remove_Hash(hash_t *hash, int key) {
  int h = key % MAX_SIZE;
  if(hash->table[h] == NULL) {
    printf("Key nonexistent.\n");
  }
  else {
    remove_List(hash->table[h], key);
  }
}

int containsKey_Hash(hash_t *hash, int key) {
  int h = key % MAX_SIZE;
  if(hash->table[h] == NULL) {
    printf("Key nonexistent.\n");
    return 0;
  }
  else {
    int value = search_List(hash->table[h], key);
    if(value == INT_MIN) return 0;
    else return 1;
  }
}

void show_Hash(hash_t *hash) {
  int i;
  for(i = 0; i < MAX_SIZE; i++) {
    if(hash->table[i] != NULL) {
      showFront_List(hash->table[i]);
    }
  }
}

// List
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

void addRear_List(list_t *list, int value, int key) {
  node_t *newNode = (node_t*) malloc(sizeof(node_t));
  newNode->value = value;
  newNode->key = key;
  list->size += 1;
  if(list->rear == NULL) {
    list->rear = list->front = newNode;
  }
  else {
    list->rear->next = newNode;
    list->rear = newNode;
  }
}

int search_List(list_t *list, int key) {
  if(list->front == NULL) {
    printf("Key nonexistent.\n");
    return INT_MIN;
  }
  else {
    if(list->front->key == key) { 
      return list->front->value;
    }
    else { 
      list->front = list->front->next;
      return search_List(list, key);
    }
  }
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
  showFront(list->front);
}
