#include <stdio.h>
#include <stdlib.h>



int largest(int * data, int size){
    if(size==0){
        return -1;
    }

    int largest_index = 0;
    for(int i=0; i< size-1 ;i++ ){
        if(data[largest_index] < data[i+1]){
            largest_index = i + 1;
        }
    }

    return data[largest_index];
}

int main(void){
    int data[] = {17,24,99,3,32,15,235,1,12,33};

    int size = sizeof(data) / sizeof(data[0]);
    int answer  = largest(data, size);
    printf("answer is : %d\n", answer);
    return EXIT_SUCCESS;
}