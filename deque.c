
#include "deque.h"
#include <stdlib.h>

//inicia um novo deque
void deque_init(deque *lista, int len ){
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	lista->len = 0;
	lista->maxlen = len;
}


//insere elmento no inicio 
int deque_insereI(deque *lista, int data){

	if(lista->len < lista->maxlen){

		//definindo novo no (item)
		node *n = (node*)malloc(sizeof(node));
		n->item = data;
		n->linkd = NULL;
		n->linke = NULL;

		if(lista->len){
			n->linke = lista->primeiro;
			lista->primeiro->linkd = n;
		}
		else{
			lista->primeiro = n;
			lista->ultimo = n;
		}

		lista->primeiro = n;
		lista->len++; //incrementando o tamanho

		return 1;	//sucesso
	}

	return 0; //fila cheia
}


//insere elemento no fim 
int deque_insereF(deque *lista, int data){

	if(lista->len < lista->maxlen){

		//definindo novo no (item)
		node *n = (node*)malloc(sizeof(node));
		n->item = data;
		n->linkd = NULL;
		n->linke = NULL;

		if(lista->len){
			n->linkd = lista->ultimo;
			lista->ultimo->linke = n;
		}
		else{
			lista->primeiro = n;
			lista->ultimo = n;
		}

		lista->ultimo = n;
		lista->len++; //incrementando o tamanho

		return 1;	//sucesso
	}

	return 0; //fila cheia
}


//remove o elemento do topo do inicio
int deque_removeI(deque *lista, int *removido){

	if(lista->len > 0){

		node *n = lista->primeiro;
		*removido = lista->primeiro->item;
		lista->primeiro = n->linke;
		free(n);

		if(lista->primeiro == NULL)
			lista->ultimo = NULL;

		lista->len--; //decrementando o tamanho

		return 1;
	}

	return 0; //fila fazia
}


//remove o elemento do topo do fim
int deque_removeF(deque *lista, int *removido){

	if(lista->len > 0){

		node *n = lista->ultimo;
		*removido = lista->ultimo->item;
		lista->ultimo = n->linkd;
		free(n);

		if(lista->ultimo == NULL)
			lista->primeiro = NULL;

		lista->len--; //decrementando o tamanho

		return 1;
	}

	return 0; //fila fazia
}

void deque_destroi(deque *lista){
	int removido;

	while(lista->len > 0)
		deque_removeI(lista, &removido);

	return;
}