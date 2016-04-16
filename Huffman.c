#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	int n;
	int *index;
	char *harf;
	
}AG;

void readTree(AG *x){//AG agacýnýn okunmasý
	int i,j;
	printf("AG agacinin karakter sayisini giriniz\n");
	scanf("%d",&x->n);
	
	x->index=(int*)malloc((x->n) * sizeof(int));//Malloc ile diziler icin bellekte yer acma islemleri
	x->harf=(char*)malloc((x->n)*sizeof(char));
	
	for(i=1;i<=(x->n);i++){
		printf("%d. inci karakterin indexini giriniz",i);
		printf("\n");
		scanf("%d",&(x->index)[i]);
	}

	
	for(i=1;i<=(x->n);i++){
		printf("%d. inci karakteri giriniz",i);
		printf("\n");
		scanf(" %c",&(x->harf)[i]);
	}
	
	
}




void findPass(int huffman[],int n,AG *x,int sifre[],int size){//Gerekli parametrelerin fonksiyona verilmesi
	int i=0,j,k=0,m;
	int *frekans;
	char *decode;
	frekans=(int*)malloc(size* sizeof(int));
	decode=(char*)malloc(size * sizeof(char));
	
	
	printf("\n\n\n");
	while(i<size){// Agac üzerinde arama yaparak sifrelenmis harflerin bulunmasý
		j=1;
		while(huffman[2*j]!=0){
			if(sifre[i]==0){
				j=2*j;
			}
			else if(sifre[i]==1){
				j=2*j+1;
			}
			
			i++;
			
		}
		frekans[k]=huffman[j];// Bulunan harfin frekansýnýn frekans dizisine atýlmasý
		for(m=1;m<=(x->n);m++){
			if(j==(x->index)[m]){
				decode[k]=(x->harf)[m];//Bulunmuþ olan harfin kendisinin decode isimli degiskene atýlmasý.
			}
		}
		printf("%d %c\n",frekans[k],decode[k]);
		k++;
	
	}
		int verim=(size*100)/(k*8);// Agacýn veriminin hesaplanmasý
		printf("Agacin verimi = %d",verim);
		
	
}

int main(int argc, char *argv[]) {
	AG a;
	int b,n;
	
	readTree(&a);
	printf("Huffman dizisinin eleman sayisini giriniz");
	scanf("%d",&n);
	
	int huffman[2*n+1];
	int i;
	for(i=1;i<=2*n+1;i++){
		huffman[i]=0;
	}	
	for(i=1;i<=n;i++){
		printf("Huffman agacinin %d. inci elemanini giriniz\n",i);
		scanf("%d",&huffman[i]);
	}
	
	printf("CO dizisinin eleman sayisini giriniz");
	scanf("%d",&b);
	int c[b];
	for(i=0;i<b;i++){
		scanf("%d",&c[i]);
	}
	
	findPass(huffman,2*n+1,&a,c,b);
	return 0;
}
