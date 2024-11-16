#include<stdio.h>

main(){
    int Result=0, i=0, arr[5]={2,5,7,9,0};
    while(i<5){
        Result+=arr[i];
        i++;
    }
    printf("Result: %d",Result);
}