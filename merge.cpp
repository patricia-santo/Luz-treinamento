#include<stdio.h> 
#include<stdlib.h>

void merge(int *saida, int *auxiliar, int inicio, int meio, int fim){
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    
    while(i <= meio && j <= fim){
        if(auxiliar[i] < auxiliar[j]){
            saida[k] = auxiliar[i];
            i++;
        }
        else{
            saida[k] = auxiliar[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        saida[k] = auxiliar[i];
        i++;
        k++;
    }

    while(j <= fim){
        saida[k] = auxiliar[j];
        j++;
        k++;
    }
    //Copia os elementos que foram ordenados para o auxiliar
    for(int p = inicio; p <= fim; p++)
        auxiliar[p] = saida [p];
}


void mergeSort(int *saida, int *auxiliar, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(saida, auxiliar, inicio, meio);
        mergeSort(saida, auxiliar, meio + 1, fim);
        merge(saida, auxiliar, inicio, meio, fim);
    	}
   }
   
   int main(){
  	
   int *auxiliar,*saida,tamanho;
  	
   printf("Escreva o numero de termos\n");     
   scanf("%d", &tamanho);   
    
   auxiliar = (int*)malloc(tamanho*sizeof(int));     
   saida = (int*)malloc(tamanho*sizeof(int)); 
  
   printf("Digite os numeros\n");     
   for (int i = 0; i < tamanho; i++){         
   scanf("%d", &auxiliar[i]);    
   
   } 
  
    mergeSort(saida,auxiliar,0, tamanho-1);
    
    printf("\nOs numeros ordenados sao\n");     
	for(int i = 0; i < tamanho; i++){         
	printf("%3d", auxiliar[i]); 
	    
	}   
	  
	return 0; 
  
}
