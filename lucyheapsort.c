#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 10

void heapify(int *heap);
void seed_heap(int *heap);
void sort_heap(int *heap);
void sift_down(int *heap, int start, int end);
void swap(int *heap, int a, int b);
void possibly_better_swap(int *heap, int a, int b);
void print_heap(int *heap);

int main(){
    int *heap = malloc(LEN*sizeof(int));
    seed_heap(heap);
    print_heap(heap);
    sort_heap(heap);
    print_heap(heap);
    free(heap);
    return 0;
}

void print_heap(int *heap){
    printf("[ ");
    for(int i = 0; i < LEN; i++)
        printf("%d, ", heap[i]);
    printf("]\n");
}

void seed_heap(int *heap){
    srand(time(0));
    for(int i = 0; i < LEN; i++){
        heap[i] = rand() % LEN;
    }
}

void heapify(int *heap){
    for(int start = (LEN-2)/2; start >= 0; start--){
        sift_down(heap, start, LEN-1);
    }
}

void sift_down(int *heap, int start, int end){
    while((start*2)+1 <= end){
        int child = (start*2)+1;
        if((child+1 <= end) && (heap[child] < heap[child+1]))
            child++;
        if(heap[start]<heap[child]){
            possibly_better_swap(heap, heap[start], heap[child]);
            start = child;
        }
        else{
            return;
        }
    }            
}

void sort_heap(int *heap){
    // Make heap[0] the largest number in heap
    heapify(heap);
    // Get the ever-shortening length of the heap
    for(int end=LEN-1; end>0; end--){
        possibly_better_swap(heap, heap[end], heap[0]);
        sift_down(heap, 0, end-1);
    }         
}

void swap(int *heap, int a, int b){
    /* XOR is pretty nifty. 
    This magical swapping algorithm first creates a 'hybrid' of both a and b 
    (both of which are N-length binary numbers, in this case integers),
    which is the output of their XOR (recall that it's when only one or the other has a 1).
    Then, the second XOR call acts on that hybrid, which is now stored in 'a', 
    and XORs it with 'b'.  Here, we should note that if you XOR something with itself,
    it zeros out.  This intuitively makes sense, as all of the numbers will be the same,
    which by the very nature of XOR makes them all output zero.  By calling XOR
    on the a-b hybrid with b, we essentially cancel out all of the 'b' in formation
    in the hybrid, leaving only 'a' information.  So now b == old a.  Now that b
    holds all the information the original a did, if we XOR it with the hybrid, it
    will cancel all the original-a information, and leave only original-b information.
    And then your numbers are swapped!  For a better explanation, see 
    http://betterexplained.com/articles/swap-two-variables-using-xor/ 
    WARNING if you try to 'swap' two variables that are the same, THEY WILL ZERO 
    OUT AND EVERYTHING YOU KNOW AND LOVE WILL DIE!  Just something to keep in mind*/
    heap[a] ^= heap[b];
    heap[b] ^= heap[a];
    heap[a] ^= heap[b];
}

void possibly_better_swap(int *heap, int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}
