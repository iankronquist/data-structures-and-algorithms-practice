#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Includes char *HAMLET_LINES[] and HAMLET_NUM_LINES
#include "hamlet_data.h"

#define FILTER_SIZE 2048

unsigned long hash(const char* data);
int contains(int *arr, int arr_len, unsigned long index);
int train(int *arr, int arr_len, unsigned long index);
int main() {
    int *filter = malloc(FILTER_SIZE * sizeof(int));
    memset(filter, 0, FILTER_SIZE * sizeof(int));
    int num_collisions = 0;
    unsigned long hash_index;
    for (int i = 0; i < HAMLET_NUM_LINES/2; i++) {
        hash_index = hash(HAMLET_LINES[i]);
        train(filter, FILTER_SIZE, hash_index);
    }
    for (int i = 0; i < HAMLET_NUM_LINES/2; i++) {
        if (!contains(filter, FILTER_SIZE, hash(HAMLET_LINES[i]))) {
            printf("ERROR: false negative with the line: %s\n", HAMLET_LINES[i]);
        }
    }
    for (int i = HAMLET_NUM_LINES/2; i < HAMLET_NUM_LINES; i++) {
        if (contains(filter, FILTER_SIZE, hash(HAMLET_LINES[i]))) {
            num_collisions++;
        }
    }
    printf("There were %i collisions\n", num_collisions);
    return 0;
}

unsigned long hash(const char* data) {
    // The FNV hash function
    const unsigned long FNV_offset_basis = 0xcbf29ce484222325;
    const unsigned long FNV_prime = 0x100000001b3;
    unsigned long hash = FNV_offset_basis;
    for (int i = 0; data[i] != '\0'; i++) {
        hash *= FNV_prime;
        hash ^= data[i];
    }
    /*
    unsigned long hash = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        hash += data[i];
    }
    */
    return hash;
}

int contains(int *arr, int arr_len, unsigned long index) {
    int which_int = (index / sizeof(int)) % arr_len;
    int which_bit = index % sizeof(int);
    return arr[which_int] & (1 << which_bit);
}

int train(int *arr, int arr_len, unsigned long index) {
    int which_int = (index / sizeof(int)) % arr_len;
    int which_bit = index % sizeof(int);
    arr[which_int] |=  1 << which_bit;
    return 0;
}
