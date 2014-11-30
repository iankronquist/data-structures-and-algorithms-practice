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
    int *heap = malloc(heapl*sizeof(int));
    seed_heap(heap, heapl);
    print_heap(heap, heapl);
    sort_heap(heap, heapl);
    print_heap(heap, heapl);
    verify_heap(heap, heapl);
    free(heap);
    return 0;
}

void print_heap(int *heap, int heapl) {
    printf("[ ");
    for (int i = 0; i < heapl; i++) {
        printf("%i, ", heap[i]);
    }
    printf("]\n");
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
        //        print_heap(heap, heapl);
    }
    for (int i = heapl-1; i >= 1; i--) {
        swap(heap, 0, i);
        sift_down(heap, 0, i-1);
    }
}

void swap(int *heap, int a, int b) {
    //printf("swapping %i %i\n", heap[a], heap[b]);
    heap[a] ^= heap[b];
    heap[b] ^= heap[a];
    heap[a] ^= heap[b];
}

void sift_down(int *heap, int index, int bottom) {
    int childl = index * 2;
    if (childl >= bottom){
        /* In this case childl can be out of bounds of the array, since you are passing it 
           the *length* and not the last index of the array (ie. heap[9] when length is 10), 
           which is throwing an out of bounds error.  You can get rid of this by just having 
           it return, as your heap is already heapified.*/
        return;
    }
    int childr = index * 2 + 1;
    int follow = index;
    else if (heap[childr] > heap[childl]) 
        follow = childr;
    else 
        follow = childl;
    if (heap[index] < heap[follow])
        swap(heap, index, follow);
    if(follow == index) 
        return;
    sift_down(heap, follow, bottom);
}
