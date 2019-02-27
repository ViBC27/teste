#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct heap heap_t;
struct heap {
  int size;
  int data[MAX_SIZE];
};

heap_t* newHeap();
void enqueue(heap_t *heap, int item);
int dequeue(heap_t *heap);
int get_parent_index(heap_t *heap, int i);
int get_left_index(heap_t *heap, int i);
int get_right_index(heap_t *heap, int i);
void max_heapify(heap_t *heap, int i);
int item_of(heap_t *heap, int i);
void heapsort(heap_t *heap);
int is_empty(heap_t *heap);
void swap(int *a, int *b);
void showHeap(heap_t *heap);

int main() {
  heap_t *heap = newHeap();
  enqueue(heap, 10);
  enqueue(heap, 17);
  enqueue(heap, 56);
  showHeap(heap);
  dequeue(heap);
  showHeap(heap);
}

heap_t* newHeap() {
  heap_t* heap = (heap_t*) malloc(sizeof(heap_t));
  heap->size = 0;
  return heap;
}

void enqueue(heap_t *heap, int item) {
  if (heap->size >= MAX_SIZE) {
    printf("Heap overflow\n");
  } 
  else {
    heap->data[++heap->size] = item;
    int key_index = heap->size;
    int parent_index = get_parent_index(heap, heap->size);
    while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index]) {
      swap(&heap->data[key_index], &heap->data[parent_index]);
      key_index = parent_index;
      parent_index = get_parent_index(heap, key_index);
    }
  }
}

int dequeue(heap_t *heap) {
  if(is_empty(heap)) {
    printf("Heap underflow\n");
    return -1;
  } 
  else {
    int item = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    max_heapify(heap, 1);
    return item;
  }
}

int is_empty(heap_t *heap) {
  return (heap->size == 0);
}

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void max_heapify(heap_t *heap, int i) {
  int largest;
  int left_index = get_left_index(heap, i);
  int right_index = get_right_index(heap, i);
  if(left_index <= heap->size &&
    heap->data[left_index] > heap->data[i]) {
    largest = left_index;
  }
  else {
    largest = i;
  }
  if(right_index <= heap->size && heap->data[right_index] > heap->data[largest]) {
    largest = right_index;
  }
  if(heap->data[i] != heap->data[largest]) {
    swap(&heap->data[i], &heap->data[largest]);
    max_heapify(heap, largest);
  }
}

void heapsort(heap_t *heap) {
  int i;
  for(i = heap->size; i >= 2; i--) {
    swap(&heap->data[1], &heap->data[i]);
    heap->size--;
    max_heapify(heap, 1);
  }
}

void showHeap(heap_t *heap) {
  int i;
  for(i = 1; i <= heap->size; i++) {
    printf("%d ", heap->data[i]);
  }
  printf("\n");
  //printf("%d\n", heap->data[MAX_SIZE - 1]);
}

int get_parent_index(heap_t *heap, int i) {
  return i/2;
}
int get_left_index(heap_t *heap, int i) {
  return 2*i;
} 
int get_right_index(heap_t *heap, int i) {
  return 2*i + 1;
}
int item_of(heap_t *heap, int i) {
  return heap->data[i];
}