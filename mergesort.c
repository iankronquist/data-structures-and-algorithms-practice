#include<stdio.h>
void mergesort(int* list, int low, int high);
void merge(int* list, int low, int half, int high);

void print_list(int * list, int len){
    // Print any list of longs in format [ 0 10 100 ]
    int i;
    printf("[ ");
    for (i = 0; i < len; i++)
        printf("%d ", list[i]); 
    printf("]\n");
}


void mergesort(int* list, int low, int high){ 
    if(high-low <= 1)
        return ;
    int half = (low+high)/2;
    mergesort(list, low, half);
    mergesort(list, half, high);
    merge(list, low, half, high);
}

void merge(int* list, int low, int half, int high){
    //Get the lengths of each "half" of the list
    int left_length = half-low;
    int right_length = high-half;
    int l = 0, r = 0, i = 0;
    //Temporary sublists to sort
    int left[left_length];
    int right[right_length];

    //Copy original list values into temporary lists
    for(i = low; i<half; i++, l++)
        left[l] = list[i];
    for(int i = half; i<high; i++, r++)
        right[r] = list[i];

    //Merge back into list
    //Find which value is lower between the left sublist and right sublist, and then replace
    //the value in the original list with that value.
    //Rinse repeat.
    for(i = low, r=0, l=0; l<left_length && r<right_length; i++){
        if(left[l]<right[r]){
            list[i] = left[l];
            l++;
        } else {
            list[i] = right[r];
            r++;
        }

    }
    for( ; l<left_length; i++, l++)
        list[i] = left[l];
    for( ; r<right_length; i++, r++)
        list[i] = right[r];
}

int main(){
    //Test list to test
    int list[20] = {3, 92, 33, 20, 34, 95, 74, 3, 1, 20, 47, 38, 19, 11, 23, 24, 85, 872, 38, 10};
    print_list(list, 20);
    mergesort(list, 0, 20);
    print_list(list, 20);
    return 0;
}
