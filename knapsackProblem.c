#include "stdlib.h"
#include "stdio.h"

int max(int a,int b);

int knapSack(int capacity,int wt[],int val[],int n);

int main(int argc, char const *argv[])
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
	return 0;
}

int max(int a,int b)
{
	return (a>b) ? a : b;
}

int knapSack(int capacity,int wt[],int val[],int n)
{
	int i;
	int j;
	int K[n+1,capacity+1];

	for (i = 0; i <=n; i++)
	{
		for (j = 0; j <= capacity; j++)
		{
			if(j==0 || i ==0)
				K[i][j]=0;
			else if(wt[i-1]<=j)
				K[i][j]=max(val[i-1]+K[i-1][j-wt[i-1]],K[i-1][j]);
			else
				K[i][j]=K[i-1][j];
		}
	}
	return K[n][capacity];
}