#include <stdio.h>
# include <iostream>
# include <stdlib.h>
using  namespace std;

void insertion(int *vet, int n)
{
	int i, j, aux;
	
	for (i=1; i < n; i++){
		aux = vet[i];
		j = i - 1;
		
		while (j >=0  && aux < vet[j]){
			vet [j+1] = vet[j];
			j--;
		}
		vet [j + 1] = aux;
	}
}


int main (){
	
	int *vet,n, aux;
	
	printf ("\t\tMETODOS DE ORDENACAO POR INSERCAO!\n\n");
	
	printf ("\t\tINSIRA A QUANTIDADE DE NUMEROS:\n\n");
	scanf ("%d", &n);
	vet = (int*) malloc (n * sizeof(int));
	
   
   printf("DIGITE CADA NUMERO:\n");
 		for (int i=0; i < n; i++){
 		scanf("%d", &vet[i]);
 }
		insertion (vet,n);
	    printf("\n");
	 	printf("NUMEROS ORDENADOS:\n");
	 	
 	for(int i=0;i<n;i++){
		printf("%3d",vet[i]);
	}
	free (vet);
	return 0;
}
