#include<stdio.h>
#include<ctype.h>
#include<string.h>

int vowelcount=0,consocount=0,spacecount=0;
int vowelcheck(char *ss){
    int i,j=0;
    char s[strlen(ss)];
	 strcpy(s, strlwr(ss));
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||
        s[i]=='o' || s[i]=='u'){
            vowelcount++;
        }
    }
    return vowelcount;
}
int main(){
//    int v=0, c=0, s=0, j;
    char str[]={"I LOVE YOU"};
//    char vowel[5]={'a','e','i','o','u'};
//    for(int i=0; str[i]!='\0';i++){
//        for(j=0; j<5; j++)
//        if(tolower(str[i])==vowel[j])
//        v++;
//        if(str[i]==32)
//        s++;
//        else if(isalpha(str[i]))
//        c++;
//    }


     printf("%d", vowelcheck(str));

//    printf("No of Vowel: %d\n",v);
//    printf("No of Consonent: %d\n",c);
//    printf("No of Space: %d",s);
    return 0;
}
