#include "stdio.h"
#include "stdlib.h"

int max(int a,int b);

int knapsack(int maxWeight,int weight[],int weightIndex,int val[],int valIndex);

int main(int argc, char const *argv[])
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  maxWeight = 50;
    int valIndex=2;
    int weightIndex=2;

    printf("%d\n", knapsack(maxWeight,wt,weightIndex,val,valIndex)); 
	return 0;
}

int max(int a,int b)
{
	return (a>b) ? a : b ;
}

int knapsack(int maxWeight,int weight[],int weightIndex,int val[],int valIndex)
{
	int dp[valIndex+1][maxWeight+1];
	int i;
	int j;

	for (i = 0; i <= valIndex; i++)
	{
		for (j = 0; j <=maxWeight ; j++)
		{
			if (j==0)
               dp[i][j] = 0;
			else if(weight[i]<=maxWeight)
				dp[i][j]=max(val[i]+dp[i-1][maxWeight-weight[i]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];

		}	
	}

	return dp[weightIndex][maxWeight];
}
