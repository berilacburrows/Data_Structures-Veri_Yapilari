#include "stdio.h"
#include "stdlib.h"

void mergeSort(int a[],int p,int r);

void merge(int a[],int p,int q,int r);

int main(int argc, char const *argv[])
{	
	int dizi[10]={3,1,6,2,768,23,96,46,12,19};
	printf("abc\n");
	mergeSort(dizi,0,9);
	return 0;
}

void mergeSort(int a[],int p,int r)
{
	int q,j;

	if(p<r)
	{
		q=(p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q,r);
		merge(a,p,q,r);
		for(j=0;j<=r;j++){
			printf("%d\n", a[j]);
		}
	}
}

void merge(int a[],int p,int q,int r)//p=0 initial
{
	int b[100];
	int i,k=0,j;

	i=p;
	j=q+1;

	while((i<=q)&&(j<=r))
	{
		if (a[i]<=a[j])
		{
			b[k++]=a[i++];
		}else
		{
			b[k++]=a[j++];
		}
	}

	while(i<=q){
		b[k++]=a[i++];
	}
	while(j<=r){
		b[k++]=a[j++];
	}

	k=0;
	i=p;

	while(i<=r){
		a[i]=b[k];
		i++;
		k++;
	}
	
}