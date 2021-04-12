#include <stdio.h>
# include <stdlib.h>



void selecao (int *vet, int tam){
    int min, x,i;
    
    for (int i=0; i< tam; i++){
        min = i;
			
    for (int j=i+1; j< tam; j++){
            if (vet[min] > vet[j]){
            min = j;
    	}
	}
    	if (i!=min){
    	x = vet[i];
    	vet[i] = vet[min];
    	vet[min] = x;
    	}
	}
}
int main (){
	int *vet, tam;
	
	printf ("\t\tMETODOS DE ORDENACAO SELECTION\n\n");
	
	printf("\t\tINSIRA OS NUMEROS PARA ORDENAR:\n");
	scanf ("%d", &tam);
	
	vet = (int*) malloc (tam * sizeof(int));
	

	printf("DIGITE CADA NUMERO DO VETOR\n");
		for(int i=0;i<tam;i++){
		scanf("%d", &vet[i]);
	}
        selecao(vet,tam); 
		printf ("\n");
		printf ("NUMEROS ORDENADOS:\n ");
		
	for(int i=0;i<tam;i++){
		printf("%3d",vet[i]);
	}
   
	free (vet);
 	return 0; 
}

