#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void seed_heap(int * heap, int heapl);
void verify_heap(int *heap, int heapl);
void heapify(int *heap, int heapl);
void sort_heap(int *heap,  int heapl);
void sift_down(int *heap, int heapl, int index);
void swap(int *heap, int a, int b);
void print_heap(int *heap, int heapl);
int main() {
    int heapl = 10;
    int *heap = malloc(heapl * sizeof(int));
    seed_heap(heap, heapl);
    print_heap(heap, heapl);
    sort_heap(heap, heapl);
    print_heap(heap, heapl);
    verify_heap(heap, heapl);
    free(heap);
    return 0;
}

void print_heap(int *heap, int heapl) {
    for (int i = 0; i < heapl; i++) {
        printf("%i, ", heap[i]);
    }
    printf("\n");
}

void seed_heap(int * heap, int heapl) {
    srand(time(0));
    for (int i = 0; i < heapl; i++) {
        heap[i] = rand() % 10;
    }
}

void verify_heap(int *heap, int heapl) {
    for (int i = 0; i < heapl-1; i++) {
        if (heap[i] > heap[i+1]) {
            assert(0);
        }
    }
}

void heapify(int *heap, int heapl) {
    for (int i = 0; i < heapl; i++) {
        sift_down(heap, heapl, i);
    }
}

void sort_heap(int *heap,  int heapl) {
    for (int i = heapl/2; i >= 0; i--) {
        sift_down(heap, i, heapl);
        print_heap(heap, heapl);
    }
    for (int i = heapl-1; i >= 1; i--) {
        swap(heap, 0, i);
        sift_down(heap, 0, i-1);
    }
}

void swap(int *heap, int a, int b) {
    printf("swapping %i %i\n", heap[a], heap[b]);
    heap[a] ^= heap[b];
    heap[b] ^= heap[a];
    heap[a] ^= heap[b];
}

void sift_down(int *heap, int index, int bottom) {
    int childl = index * 2;
    if (childl > bottom) return;
    int childr = index * 2 + 1;
    int follow = index;
    if (childl == bottom) {
        follow = childl;
    } else if (heap[childr] > heap[childl]) {
        follow = childr;
    } else {
        follow = childl;
    }
    if (heap[index] < heap[follow]) {
        swap(heap, index, follow);
    }
    if(follow == index) return;
    sift_down(heap, follow, bottom);
}
/*
void sift_down(int *heap, int root, int bottom)
{
  int maxChild, temp;

  while ((root*2 <= bottom))
  {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (heap[root * 2] > heap[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;

    if (heap[root] < heap[maxChild])
    {
      swap(heap, root, maxChild);
      root = maxChild;
    }
    else
        return;
  }
}*/
