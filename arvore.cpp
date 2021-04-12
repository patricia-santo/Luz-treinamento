#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	int valor;
 	struct No *proximo,*anterior;
}No;

typedef struct Arvore{
 	No* raiz;
 	int tamanho;
}Arvore;

