#include <stdio.h>
int main(){
    int i, a = 50;
    for (i = 0; i <= a; i++ ){
        if (i % 2 == 0){
            continue;
        }
        printf("%d ", i);
        // if(i/2==0)
        // i+=2;
    }
}