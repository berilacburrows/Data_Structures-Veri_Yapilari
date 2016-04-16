#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	int *A;
	int *PO;
	int n;
}linkedList;

void createList(linkedList *x){//A ve PO dizisinin olusturulmasý
	printf("Algoritma dersini alan ogrenci sayisini giriniz ");
	scanf("%d", &x->n);
	
	x->A = (int*) malloc(x->n * sizeof(int));
	x->PO = (int*) malloc(x->n * sizeof(int));
	int i ;
	
	printf("Ogrencilerin notlarini giriniz.\n");
	
	for(i = 0; i < x->n; i++)
	{
		printf("%d --> ", i + 1);
		scanf("%d", &(x->A)[i+1]);
	}
	
	printf("Kucukten buyuge sirali erisimi saglayacak sekilde linkleyen PO dizisinin elemanlarini giriniz.\n");
	for(i = 0; i <= x->n; i++)
	{
		printf("%d --> ", i + 1);
		scanf("%d", &(x->PO)[i]);
	}
	
}


void deleteStudent(linkedList *x){ // A dizisinden diger gruba gececek ogrencinin notunun silinmesi islemi
	int d;
	printf("Diger gruba gecmesini istediginiz ogrencinin notunu giriniz:");
	scanf("%d",&d);
	int k=0;
	int j;
	j=(x->PO)[0];
	
	while ((j>0) && ((x->A)[j]!=d)){
		k=j;
		j=(x->PO)[j];
	}
	
	if(d==((x->A)[j])){
		(x->PO)[k]=(x->PO)[j];
		(x->PO)[j]=-5;
	}
	else{
		printf("Bu notta bir ogrenci yok");
	}
	
}

void addStudent(linkedList *x){//A dizisine notu girilen ogrencinin eklenmesi
	int a;
	printf("Bu gruba gececek ogrencinin notunu giriniz:");
	scanf("%d",&a);
	
	int j,k;
	k=0;
	j=(x->PO)[0];
	
	while((j>0) && ((x->A)[j]<a) ){
		k=j;
		j=(x->PO)[j];
	}

	x->n=(x->n)+1;
	(x->A)[x->n]=a;
	(x->PO)[x->n]=j;
	(x->PO)[k]=x->n;
}

void printList(linkedList *x){
	int j;
	j=(x->PO)[0];
	while(j>0){
		printf("%d\n",(x->A)[j]);
		j=(x->PO)[j];
	}
}


int main(int argc, char *argv[]) {
	linkedList x;
	
	createList(&x);
	printList(&x);
	deleteStudent(&x);
	addStudent(&x);
	printList(&x);
	
	return 0;
}
