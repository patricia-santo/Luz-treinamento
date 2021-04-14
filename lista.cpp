#include <stdio.h>
#include <stdlib.h>

// cria uma estrutura de nó
typedef struct node{
	int num;
	struct node *prox;
} node;

//declaração inteiro para controlar tamanho da lista
int tam;

// funcão para alocar memoria, caso não tenha espaço é apresentado erro
node *alocar(){
	node *novo = (node *) malloc(sizeof(node));
	if (!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	return novo;
}

// função para inicializar a lista e limpa o tamanho da lista
void inicia(node *LISTA){
	LISTA->prox = NULL;
	tam = 0;
}

/* ==================== TRECHO PARA ADICIONAR ==================== */
// função para adicionar no inicio da lista
void AdicionarInicio(node *LISTA){
	node *novo = alocar();
	
	novo->prox = LISTA->prox;
	LISTA->prox = novo;
	printf("Novo elemento: ");
	scanf("%d", &novo->num);
	
	tam++;
}
// função para adicionar no fim da lista
void AdicionarFim(node *LISTA){
	node *novo = alocar();
	
	novo->prox = NULL;
	if(LISTA->prox == NULL)
		LISTA->prox = novo;
	else{
		node *tmp = LISTA->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	printf("Novo elemento: ");
	scanf("%d", &novo->num);
	
	tam++;
}
// funcao para adicionar onde o usuário quiser
void AdicionarN(node *LISTA){
	int pos, count;
	
	printf("Qual posicao desejas inserir? Escolha de [1 ate %d]: ", tam);
	scanf("%d", &pos);
	
	if(pos > 0 && pos <= tam){
		if(pos == 1){
			AdicionarInicio(LISTA);
		}
		else{
			node *atual = LISTA->prox, *anterior = LISTA;
			node *novo = alocar();
			for(count=1; count < pos; count++){
				anterior = atual; atual = atual->prox;
			}
			anterior->prox = novo;
			novo->prox = atual;
			printf("Novo elemento: ");
			scanf("%d", &novo->num);
			tam++;
		}
	}
	else{
		printf("Elemento invalido!\n");
	}
}
/* ========================== TRECHO PARA CONSULTAR ======================= */
// funcao para exibir toda lista
void ExibirLista(node *LISTA){
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		node *tmp;
		for (tmp = LISTA->prox; tmp != NULL; tmp = tmp->prox)
		printf("%d\n", tmp->num);
	}
	printf("Tamanho da lista: %d\n", tam);
	printf("\n\n");
	system("PAUSE");
}

// funcao para exbibir um determinado elemento da lista
void ExibirElementoN(node *LISTA){
	int pos, count;
	
	printf("Qual elemento desejas consultar? Escolha de [1 ate %d]: ", tam);
	printf("\n\n");
	scanf("%d",&pos);
	
	if(pos>0 && pos <= tam){
		node *atual = LISTA->prox, *anterior = LISTA;
		
		for(count=1; count < pos; count++){
			anterior = atual;
			atual = atual->prox;
		}
		system("CLS");
		printf("\n\n");
		printf("Valor do elemento %d e: %d\n",pos, atual->num);
		printf("\n\n");
		system("PAUSE");
	}
}

/* ========================== TRECHO PARA REMOVER ========================== */
// funcao para remover do inicio da lista
void RemoverInicio(node *LISTA){
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		node *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		printf("NO %d removido com sucesso!",tmp->num);
		free(tmp);
		tam--;
	}
	printf("\n\n");
	system("PAUSE");
}

// funcao para remover do final da lista
void RemoverFim(node *LISTA){
	node *aux;
	
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		node *ultimo = LISTA->prox, *penultimo = LISTA; 
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
			tam--;
		}
		penultimo->prox = NULL;
		printf("NO %d removido com sucesso!",ultimo->num);
	}
	printf("\n\n");
	system("PAUSE");
}

//funcao para remover de qualquer elemento
void RetirarN(node *LISTA){
	int pos, count;
	
	printf("Qual posição desejas retirar? Escolha de [1 ate %d]: ", tam);
	scanf("%d",&pos);
	
	if(pos>0 && pos <= tam){
		if(pos==1){
			return RemoverInicio(LISTA);
		}
		else{
			node *atual = LISTA->prox, *anterior = LISTA;
			
			for(count=1; count < pos; count++){
				anterior = atual;
				atual = atual->prox;
			}
			
			anterior->prox=atual->prox;
			tam--;
			printf("Elemento %d removido com sucesso!",atual->num);
			system("PAUSE");
		}
	}
}
/* ======================= LIBERA A LISTA =============================== */
// funcao para liberar a lista de memoria
void Liberar(node *LISTA){
	node *atual = LISTA->prox, *proximo;
	while(atual != NULL){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	
	inicia(LISTA);
}
/* =================== MENU PRINCIPAL E FUNCAO MAIN ====================== */

int main(void){
	
	node *LISTA = alocar();
	inicia(LISTA);
	int opt;
	
	do{
		system("CLS");
		printf("==================================\n");
		printf(" LISTA SIMPLESMENTE ENCADEADA \n");
		printf("==================================\n");
		printf(" 1-Inserir no inicio da lista\n");
		printf(" 2-Inserir no fim da lista\n");
		printf(" 3-Inserir em um ponto da lista\n");
		printf(" 4-Remover do inicio da lista\n");
		printf(" 5-Remover do fim da lista\n");
		printf(" 6-Remover de um ponto da lista\n");
		printf(" 7-Exibir elementos da lista \n");
		printf(" 8-Consultar elemento \n");
		printf(" 9-Liberar os elementos da lista \n");
		printf(" 0-Sair \n");
		printf("==================================\n");
		printf("Escolha a opcao: ");
		scanf("%d", &opt);
		system("CLS");
		
		switch(opt)
		{
			case 1: 
				AdicionarInicio(LISTA);
				break;
			case 2: 
				AdicionarFim(LISTA);
				break;
			case 3: 
				AdicionarN(LISTA);
				break;
			case 4: 
				RemoverInicio(LISTA);
				break;
			case 5: 
				RemoverFim(LISTA);
				break;
			case 6: 
				RetirarN(LISTA);
				break;
			case 7: 
				ExibirLista(LISTA);
				break;
			case 8: 
				ExibirElementoN(LISTA);
				break;
			case 9: 
				Liberar(LISTA);
				ExibirLista(LISTA);
				break;
			case 0: 
				Liberar(LISTA);
				break;
			default: 
				printf("Comando invalido\n\n");
		}
	}while(opt <= 9 && opt != 0);
	Liberar(LISTA);
	return 0;
}
