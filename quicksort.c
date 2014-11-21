#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void seed_arr(int * arr, int arrl);
void verify_arr(int *arr, int arrl);
void arrify(int *arr, int arrl);
void sort_arr(int *arr,  int arrl);
void sift_down(int *arr, int arrl, int index);
void swap(int *arr, int a, int b);
void print_arr(int *arr, int arrl);

int main() {
    int arrl = 10;
    int *arr = malloc(arrl * sizeof(int));
    seed_arr(arr, arrl);
    print_arr(arr, arrl);
    sort_arr(arr, arrl);
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

void sort_arr(int *arr,  int arrl) {
    // FIXME
}

void swap(int *arr, int a, int b) {
    // FIXME: Explain why this works
    arr[a] ^= arr[b];
    arr[b] ^= arr[a];
    arr[a] ^= arr[b];
}
