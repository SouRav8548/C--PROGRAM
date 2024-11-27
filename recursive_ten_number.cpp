#include<stdio.h>

//#define i,n
int recursive(int num[],int n){
	if(n==0)
		return 0;
	else
		return num[n-1]+recursive(num,n-1);
}
int main(){
	int num[10]={1,1,1,1,1,1,1,1,1,1};
	int res=recursive(num,10);
	printf("\nResult= %d",res);
	return 0;
}

