#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

//Compara pares de elementos adjacentes e os troca de lugar se estiverem na ordem errda
// Esse processo se repete até que mais nenhuma troca seja necessaria (eementos já ordenados)

//Performace
// - Melhor Caso: O(N) n operacoes sao necessarias para vc ordenar, ou seja os dados ja estao ordenados, ele so passa uma vez verificando
// - Pior Caso: O (N2) tem desempenho ruim 
// - Não recoendado para grandes conuntos de dados
//
void bubble(int *n, int tam, int temp){ 
    //for para iniciar o vetor 
    for (int i = 0; i < tam; i++) {
        n[i] = 1 + rand() % tam; // usei para comecar de 1 e nao de 0
    }
   // percorrer o vetor inteiro
	for(int i=0;i<tam;i++)
	{
		bool troca = false; // verificacao para ver se os numeros a estao ordenados
		//percorrer o vetor por pares
		for(int j=0;j<(tam-1);j++) 
		{
			if(n[j]>n[j+1]) 
			{
				temp=n[j];// se a possicao da esquerda for maior que a da direita, exemplo 5 4
				n[j]=n[j+1]; // entao troca
				n[j+1]=temp; // entao troca
				troca = true; // aqui diz que a troca aconteceu
			}
		}
		// caso nao entre aqui diz que a troca nao e necessaria evitando looping
		if(troca==false){
			break;
		}	
   	 }
} 
	
int main()
{
	int *n,tam,temp;
	printf ("\t\tMETODOS DE ORDENACAO POR BOLHA!\n\n");
	printf ("\t\tINSIRA O SEU VETOR:\n\n");
    cin >> tam;
    n = (int *) malloc (tam * sizeof(int)); // alocacao dinamica otimiza espaco na memoria
	bubble(n,tam,temp);
	
 //for para percorrer o vetor para imprimir
	for(int i=0;i<tam;i++){
		cout<<" | "<<n[i]<<" | "<<endl;
	}
}
