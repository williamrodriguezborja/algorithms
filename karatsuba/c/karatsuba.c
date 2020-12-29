#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _low_high{
    int low, high;
} low_high;


int scanNum(char * name){
    int num = 0;
    printf("introduce %s number: ", name );
    scanf_s("%d", &num);
    return num;
}

int num_length(int num){
    // corner case 0
    int result = 0;
    if(num >=0 && num<10){
        return 1;
    }

    while (num>0){
        num = num/10;
        result++;
    }
    return result;
}

low_high split_number(int num, int middle){
    low_high result;
    int divisor = (int)pow(10, middle);
    if(num>divisor){
        result.low = num/divisor;
        result.high = num % divisor;
    }else{
        result.low = 0;
        result.high = num;
    }
    return result;
}


int karatsuba(int n1, int n2){
    // corner case 0
    if(n1== 0 && n2 ==0){
        return 0;
    }

    // simple case
    if(n1<10 || n2 < 10){
        return n1*n2;
    }

    int length1 = num_length(n1);
    int length2 = num_length(n2);
    int digits = max(length1, length2);
    int middle = digits / 2;

    low_high l1 =  split_number(n1, middle);
    low_high l2 =  split_number(n2, middle);

    int a = l1.low;
    int b = l1.high;
    int c = l2.low;
    int d = l2.high;


    int s1 = karatsuba(a, c);
    int s2 = karatsuba(b, d);
    int s3 = karatsuba(a,d) + karatsuba(b,c);

    return s1 * (int)pow(10, digits) + s3 * (int)pow(10, digits/2.0)+ s2 ;
}


int main(){
    int n1 = scanNum("n1");
    int n2 = scanNum("n2");
    printf("%d",karatsuba(n1,n2));
    return EXIT_SUCCESS;
}
