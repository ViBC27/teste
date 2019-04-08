#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

typedef struct binary_tree binary_tree;
typedef struct node node_t;
typedef struct deque deque_t;
struct binary_tree {
  int item;
  binary_tree *left;
  binary_tree *right;
};
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

binary_tree* newEmptyBinaryTree();
binary_tree* newBinaryTree(int item, binary_tree *left, binary_tree *right);
void newRoot(binary_tree **tree, deque_t *deque);
void readTree(binary_tree *tree, deque_t *deque);
void isBinary(binary_tree *tree, int *isBin);
int is_empty(binary_tree *tree);
void dfs(binary_tree *tree, int item, int *depth, int i);
void print_pre_order(binary_tree *tree);

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

void readInput(binary_tree *tree, deque_t *deque) { 
  char input[200];
  fgets(input, 200, stdin);
  int i, found = 0, value = 0;
  for(i = 0; input[i]; i++) {
    if(isdigit(input[i])) {
      value = value * 10 + (input[i] - '0');
      found = 1;
    }
    else {
      if(input[i - 1] == '(' && input[i] == ')') {
        enqueueRear_Deque(deque, -1);
      }
      else if(found) {
        enqueueRear_Deque(deque, value);
        found = value = 0;
      }
    }
  }
}

int main() {
  binary_tree *tree = newEmptyBinaryTree();
  deque_t *deque = new_Deque();
  int item = 4, depth = -1;
  readInput(tree, deque);
  if(!isEmpty_Deque(deque)) {
    newRoot(&tree, deque);
    readTree(tree, deque);
  }
  else return 0;
  int isBin = 1;
  dfs(tree, item, &depth, 0);
  isBinary(tree, &isBin);
  printf("is Binary: %d\n", isBin);
  if(depth != -1) printf("Ok\n");
  return 0;
}

// Tree
binary_tree* newEmptyBinaryTree() {
  return NULL;
}

binary_tree* newBinaryTree(int item, binary_tree *left, binary_tree *right) {
  binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
  new_binary_tree->item = item;
  new_binary_tree->left = left;
  new_binary_tree->right = right;
  return new_binary_tree;
}

void newRoot(binary_tree **tree, deque_t *deque) {
  *tree = newBinaryTree(dequeueFront_Deque(deque), NULL, NULL);
}

void readTree(binary_tree *tree, deque_t *deque) {
  if(tree->item == -1) return;
  if(!isEmpty_Deque(deque)) {
    tree->left = newBinaryTree(dequeueFront_Deque(deque), NULL, NULL);
    readTree(tree->left, deque);
  }
  if(!isEmpty_Deque(deque)) {
    tree->right = newBinaryTree(dequeueFront_Deque(deque), NULL, NULL);
    readTree(tree->right, deque);
  }
}

void isBinary(binary_tree *tree, int *isBin) {
  if(tree->item == -1) return;
  else {
    if(tree->left != NULL) {
      if(tree->left->item > tree->item) {
        *isBin = 0;
        return;
      }
      else {
        isBinary(tree->left, isBin);
      }
    }
    if(tree->right != NULL) {
      if(tree->right->item < tree->item && tree->right->item != -1) {
        *isBin = 0;
        return;
      } 
      else {
        isBinary(tree->right, isBin);
      }
    }
  }
}

int is_empty(binary_tree *tree) {
  return (tree == NULL);
}

void dfs(binary_tree *tree, int item, int *depth, int i) {
  if(tree->item != -1) {
    if(tree->item == item) *depth = i;
    dfs(tree->left, item, depth, i + 1);
    dfs(tree->right, item, depth, i + 1);
  }
}

void print_pre_order(binary_tree *tree) {
  if(tree->item != -1) {
    printf("(%d", tree->item);
    print_pre_order(tree->left);
    print_pre_order(tree->right);
    printf(")");
  }
  else {
    printf("()");
  }
}

// Deque
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