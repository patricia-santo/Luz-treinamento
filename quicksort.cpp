# include  <stdio.h>
# include  <stdlib.h>

int  dividir ( int *vetor, int esq, int dir) {
    int aux; // troca de posicoes
    int cont = esq;
    

    for ( int i = esq + 1 ; i <= dir; i ++) {

        if (vetor [i] <vetor [esq]) {
            cont ++;
            aux = vetor [i];
            vetor [i] = vetor [cont];
            vetor [cont] = aux;
        }
    }

    aux = vetor [esq];
    vetor [esq] = vetor [cont];
    vetor [cont] = aux;

    return cont;
}

void  quick ( int vetor [], int esq, int dir) {
    int pos;
    if (esq <dir) {
        pos = dividir (vetor, esq, dir);
        quick (vetor, esq, pos- 1 );
        quick (vetor, pos + 1 , dir);
    }
}


int main() {
 	int *vetor, tam;
 	
 	printf ("\t\tMETODOS DE ORDENACAO POR QUICKSORTE!\n\n");
 	
 	printf("\nDIGITE A QUANTIDADE DE NUMEROS: ");
 	scanf("%d", &tam);
 	
	vetor = (int*)malloc(tam*sizeof(int));
 	
	
 	printf("\nDIGITE OS NUMEROS PARA ORDENAR:\n");
 		
	for (int i = 0; i < tam; i++){
 		scanf("%d", &vetor[i]);
 	}
 		
 	quick(vetor,0,tam);

	printf("\n");
 	printf("\n");
 	
	 for (int i = 0; i < tam; i++){
 		printf("%3d", vetor[i]);
 	}

	 free(vetor);
	 return 0;
	}




