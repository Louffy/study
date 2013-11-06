#include<iostream>
#include<stdio.h>
int m[8][8] = {0};
int length = 8;
int num = 0;
void print();
bool check(int row,int col)
{
	if(row==0)return true;
	for(int i=0; i<row; i++)
	{
		if(m[i][col] == 1)return false;
	}
	for(int i=row-1,j=col-1;i>=0,j>=0;i--,j--)
	{
		if(m[i][j]==1)return false;
	}
	for(int i=row-1,j=col+1;i>=0,j<length;i--,j++)
	{
		if(m[i][j]==1)return false;
	}
	return true;
}
void solve(int row)
{
	if(row == length)
	{
		num++;
		print();
		return;
	}
	for(int j = 0; j < length; j++)
	{
		if(check(row,j))
		{
			m[row][j]=1;
			solve(row+1);
		}
	}
}
void print()
{
	printf("----%d\n",num);
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
			printf("%d ",m[i][j]);
		printf("\n");
	}
}
int main()
{
	print();
	solve(0);
	return 0;
}	
