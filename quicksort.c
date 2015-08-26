#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void seed_arr(int * arr, int arrl);
void verify_arr(int *arr, int arrl);
void arrify(int *arr, int arrl);
void quicksort(int *arr,  int begin, int end);
void sift_down(int *arr, int arrl, int index);
void swap(int *arr, int a, int b);
void print_arr(int *arr, int arrl);
int partition(int *arr, int begin, int end);
int choose_pivot(int begin, int end);

int main() {
    int arrl = 10;
    int *arr = malloc(arrl * sizeof(int));
    seed_arr(arr, arrl);
    print_arr(arr, arrl);
    quicksort(arr, 0, arrl-1);
    print_arr(arr, arrl);
    verify_arr(arr, arrl);
    free(arr);
    return 0;
}

void print_arr(int *arr, int arrl) {
    for (int i = 0; i < arrl; i++) {
        printf("%i, ", arr[i]);
    }
    printf("\n");
}

void seed_arr(int * arr, int arrl) {
    srand(time(0));
    for (int i = 0; i < arrl; i++) {
        arr[i] = rand() % 10;
    }
}

void verify_arr(int *arr, int arrl) {
    for (int i = 0; i < arrl-1; i++) {
        if (arr[i] > arr[i+1]) {
            assert(0);
        }
    }
}

void quicksort(int *arr,  int begin, int end) {
    int pivot;
    if (begin < end) {
        pivot = partition(arr, begin, end);
        quicksort(arr, begin, pivot - 1);
        quicksort(arr, pivot + 1 , end);
    }
}

int partition(int *arr, int begin, int end) {
    int pivot = choose_pivot(begin, end);
    int pivot_val = arr[pivot];
    swap(arr, pivot, end);
    int store_index = begin;
    for (int i = begin; i < end; i++) {
        if (arr[i] < pivot_val) {
            swap(arr, i, store_index);
            store_index++;
        }
    }
    swap(arr, store_index, end);
    return store_index;
}

int choose_pivot(int begin, int end) {
    // TODO: implement median choice, or random choice
    return (end-begin)/2 + begin;
}

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
    /*
    arr[a] ^= arr[b];
    arr[b] ^= arr[a];
    arr[a] ^= arr[b];
    */
}
