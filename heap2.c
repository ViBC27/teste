#include <stdio.h>
#define MAX 1000

void newMaxHeap(int mA[], int size);
void maxHeapify(int mA[], int size, int i);
void heapsort(int mA[], int size); 
void swap(int *a, int *b);
int getLeft(int i);
int getRight(int i);

int readHeap(int mA[]) {
  int n, i = 0;
  while(scanf("%d", &n) != EOF) {
    mA[++i] = n;
  }
  return i;
}

void showHeap(int mA[], int size) {
 int i;
 for(i = 1; i < size; i++) {
    printf("%d | ", mA[i]);
  }
  printf("%d\n", mA[i]);
}

int main(void) {
  int mA[MAX];
  int size = readHeap(mA);
  printf("Estado inicial: ");
  showHeap(mA, size);
  heapsort(mA, size);
  printf("Resultado Final: ");
  showHeap(mA, size);
  return 0;
}

void newMaxHeap(int mA[], int size) {
  int i;
  for(i = size/2; i >= 1; i--) {
    maxHeapify(mA, size, i);
  }
}

void maxHeapify(int mA[], int size, int i) {
  int left = getLeft(i);
  int right = getRight(i);
  int largest;
  if(left <= size && mA[left] > mA[i]) {
    largest = left;
  }
  else largest = i;
  if(right <= size && mA[right] > mA[largest]) {
    largest = right;
  }
  if(mA[i] != mA[largest]) {
    swap(&mA[i], &mA[largest]);
    maxHeapify(mA, size, largest);
  }
}

void heapsort(int mA[], int size) {
  newMaxHeap(mA, size);
  int i;
  for(i = size; i >= 1; i--) {
    printf("Estado Atual da Heap: ");
    showHeap(mA, size);
    if(i != 1) {
      printf("Maior elemento neste passo: %d\n", mA[1]);
    }
    swap(&mA[1], &mA[i]);
    size -= 1;
    maxHeapify(mA, size, 1);
  }
}

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int getLeft(int i) {
  return 2*i;
} 
int getRight(int i) {
  return 2*i + 1;
}
