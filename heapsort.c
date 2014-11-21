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
    // FIXME
}

void sort_heap(int *heap,  int heapl) {
    // FIXME
}

void swap(int *heap, int a, int b) {
    // FIXME: Explain why this works
    heap[a] ^= heap[b];
    heap[b] ^= heap[a];
    heap[a] ^= heap[b];
}

void sift_down(int *heap, int index, int bottom) {
    // FIXME
}
