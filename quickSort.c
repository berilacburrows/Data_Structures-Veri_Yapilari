#include "stdlib.h"
#include "stdio.h"

void quickSort(int a[],int p,int r);

int partition(int a[],int p,int r);

void swap(int *a,int *b);

void printArray(int a[],int n)

int main(int argc, char const *argv[])
{
	
	return 0;
}

void quickSort(int a[],int p,int r)
{
	int index;

	if(p<r)
	{
		index=partition(a,p,r);
		quickSort(a,p,index-1);
		quickSort(a,p,index+1);	
	}
}

int partition(int a[],int p,int r)
{
	int i=0;
	int j;
	int pivot=a[r];

	for(j=0;j<r;j++)
	{
		if(a[j]<=pivot)
		{
			swap(&a[i],&a[j]);
			i++;
		}
	}
	swap(&a[i+1],&a[r]);
	return (i+1);
}

void swap(int *a,int *b)
{
	int t;

	t=*a;
	*a=*b
	b*=t;
}

void printArray(int a[],int n)
{
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}