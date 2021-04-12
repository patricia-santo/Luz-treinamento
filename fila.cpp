#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct NO{
	int dado;
	struct NO *proximo;
}NO;

typedef struct FILA{
	NO *inicio;
	NO *fim;
}FILA;

void inicializaFila (FILA *f){
	f->inicio = NULL;
	f->fim = NULL;
}

void enfileira(int dado, FILA *f){
	NO *ponteiro = (NO*) malloc (sizeof(NO));
	if(ponteiro == NULL){
		printf ("Erro de alocação. \n");
		return;
	} else{
		ponteiro->dado = dado;
		ponteiro->proximo = NULL;
		if(f->inicio == NULL){
		  f->inicio = ponteiro;
		} else {
			f->fim->proximo = ponteiro;
		}
		f->fim = ponteiro;
		return;
	}
}
int desinfileira(FILA *f){
	NO *ponteiro = f->inicio;
	int dado;
	if(ponteiro != NULL){
		f->inicio = ponteiro->proximo;
		ponteiro->proximo = NULL;
		dado = ponteiro->dado;
		free(ponteiro);
		if (f->inicio == NULL){
			f->fim = NULL;
		}
		return dado;
		
	} else {
		printf("Fila vazia.\n");
	
	}
}
void imprimeFila(FILA *f){
	NO *ponteiro = f->inicio;
	if (ponteiro != NULL){
		while(ponteiro != NULL){
			printf ("%d", ponteiro->dado);
			ponteiro=ponteiro->proximo;
		}
		printf("\n");
	} else{
		printf ("Fila vazia.\n");
		return;
	}
}
int main (){
	FILA *f1 = (FILA*) malloc (sizeof(FILA));
	if(f1 == NULL){
		printf ("Erro de alocação da fila.\n");
		exit(-1);
	} else{
		inicializaFila(f1);
		
		enfileira(10, f1);
		enfileira(20, f1);
		enfileira(30, f1);
		
		imprimeFila(f1);
		
		printf ("Tentando desenfileirar - resultado: %d\n", desinfileira(f1));
		imprimeFila(f1);
		printf ("Tentando desenfileirar - resultado: %d\n", desinfileira(f1));
		imprimeFila(f1);
		printf ("Tentando desenfileirar - resultado: %d\n", desinfileira(f1));
		desinfileira(f1);
	}
}

