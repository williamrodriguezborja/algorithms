#include <stdio.h>
#include <stdlib.h>

 typedef struct struct_low_high{
     int * low;
     int low_size;
     int * high;
     int high_size;
 } low_high;

void printArray(int * array , int size){

    printf("[");
    for(int i =0; i< size; i++){
        printf("%d ", array[i] );
    }
    printf("]\n");
}

low_high splitArray(int * array, int size) {
    low_high result;
    // corner case 0
    if(size == 0){
        return result;
    }

    //int * current = array;
    int middle = size / 2;

    int low[middle];
    int high[middle];
    int low_size= 0;
    int high_size =0;
    for (int i = 0 ; i < size; i++){
        if(i<=middle){
            low[low_size]  = array[i];
            low_size++;
        }else{
            high[high_size]  = array[i];
            high_size++;
        }
    }

    printf("array:\t");
    printArray(array, size);
    printf("low:\t");
    printArray(low, low_size);
    printf("high:\t");
    printArray(high, high_size);
 
    result.low = low;
    result.low_size = low_size;
    result.high = high;
    result.high_size = high_size;
    return result;
}

int main(void){
    int data[] = {35,64,25,1,77,96,-1,64,32,15};
    int size  = sizeof(data) / sizeof(data[0]);

    low_high  split = splitArray(data, size);
    return EXIT_SUCCESS;
}
