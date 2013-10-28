#include<iostream>
#include<stdio.h>
int main()
{
	int f[4][4],n[4][4],m[10] = {3,1,5,2,4,3,6,5,4,2};
	int len = 1;
	int k=0;
	for(int i = 0; i<4;i++){
		for(int j=0;j<len;j++){
			n[i][j]=m[k];
			k++;
		}
		len++;
	}
	for(int i=0;i<len;i++){
		f[3][i]=n[3][i];
		printf("%d ",f[3][i]);
	}
	printf("\n");
	len=3;
	for(int i = 2;i>=0;i--){
		for(int j=0;j<len;j++){
			if(f[i+1][j]<f[i+1][j+1])
				f[i][j]=f[i+1][j]+n[i][j];
			else f[i][j]=f[i+1][j+1]+n[i][j];
		}
		len--;
	}
	printf("%d----\n",f[0][0]);
		
}
		
