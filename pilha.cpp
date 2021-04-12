#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct NO{
	int dado;
	struct NO *proximo;
	
}NO;

typedef struct PILHA{
	NO *topo;
}PILHA;

void inicializaPilha(PILHA *p){
	p->topo = NULL;
	
}
void empilha(int dado, PILHA *p){
	NO *ponteiro = (NO*) malloc (sizeof(NO));
	if (ponteiro == NULL){
		printf("Erro de alocação.\n");
		return;
	} else{
		ponteiro->dado = dado;
		ponteiro->proximo = p->topo;
		p->topo = ponteiro;
	}
}
int desempilha (PILHA *p){
	NO* ponteiro = p->topo;
	int dado;
	if (ponteiro == NULL){
		printf ("Pilha vazia.\n");
		//return;
	} else {
		p->topo = ponteiro->proximo;
		ponteiro->proximo = NULL;
		dado = ponteiro -> dado;
		free(ponteiro);
		return dado;
	}
	
}
void imprimePilha (PILHA *p){
	NO *ponteiro = p->topo;
	if (ponteiro == NULL){
		printf ("Pilha vazia.\n");
		return;
	} else{
		while (ponteiro != NULL){
			printf ("%d", ponteiro->dado);
			ponteiro = ponteiro->proximo;
			
		}
		printf("\n");
	}
	
}
int main (){
	PILHA *p1 = (PILHA*) malloc (sizeof(PILHA));
	if(p1 == NULL){
		printf("Erro de alocação da pilha.\n");
		exit(0);
	} else{
		
		inicializaPilha(p1);
		
		empilha(10, p1);
		empilha(20, p1);
		empilha(30, p1);
		
		imprimePilha(p1);
		
		printf ("Tentando desempilhar - resultado: %d\n", desempilha(p1));
		imprimePilha(p1);
		printf ("Tentando desempilhar - resultado: %d\n", desempilha(p1));
		imprimePilha(p1);
		printf ("Tentando desempilhar - resultado: %d\n", desempilha(p1));
		desempilha(p1);
	}
}
