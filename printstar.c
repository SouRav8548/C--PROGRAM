#include<stdio.h>

// int main(){
//     int n=10;
//     for(int i=n;i>0;i--){
//         for(int j=0;j<i;j++){
//             // if(j<n){
//                 // printf(" ");
//             // }else{
//                 printf("*");
//             // }
//         }
//         printf("\n");
//     }
//     return 0;
// }


int main() {
    int i, j, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
