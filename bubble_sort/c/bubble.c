#include <stdio.h>
#include <stdlib.h>


void swap(int *n1, int *n2){
    int  temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void printArray(int data[], int size){
    // corner case
    if(size ==0){
        return;
    }

    // corner case only one
    if (size==1){
        printf("%d", data[0]);
        return;
    }

    // problem case
    for(int i = 0 ; i < size; i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
}


void bubbleSort(int data[], int size){
    int i, j;

    for(i=0; i<size; i++)
        for(j=0; j < size - i - 1; j++)
            if(data[j]> data[j+1])
                swap(&data[j], &data[j+1]);
}

int main(void){
    int data[] = {12,33,999,3,24,69,32,14};
    int n  = sizeof(data) / sizeof(data[0]);

    printArray(data, n);
    bubbleSort(data, n);
    printArray(data, n);
    return EXIT_SUCCESS;
}