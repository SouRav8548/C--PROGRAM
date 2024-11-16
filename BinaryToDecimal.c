#include <stdio.h>
#include <string.h>
#include<math.h>

int main()
{
    printf("Write your convert Binary Number to Decimal: ");
    char binary[100];               //Define Binary string & Input from user
    scanf("%s", &binary);
    int decimal = 0, i = 0, len;
    len=strlen(binary);             //Length of Array
    for(i=0;i<len;i++){             //repeat upto length of binary string
        if(binary[i]=='1'){         //check binary string's first digit 1 or not
            decimal += pow(2,len-1-i);  //then add 2^(len-1-i) to decimal
        }else if(binary[i] != '0'){
            printf("Invalid Binary Number");
            return 1;
        }
    }
    printf("Decimal is: %d", decimal);
    return 0;
}