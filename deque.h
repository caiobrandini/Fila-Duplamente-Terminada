#ifndef DEQUE_H
#define DEQUE_H

typedef struct node_ {
	int item;
	struct node_ *linkd;
	struct node_ *linke;
} node;

typedef struct {
	node *primeiro, *ultimo;
	unsigned len, maxlen;
} deque;

void deque_init(deque *lista, int len );

int deque_insereI(deque *lista, int num);

int deque_insereF(deque *lista, int num);

int deque_removeI(deque *lista, int *removido);

int deque_removeF(deque *lista, int *removido);

void deque_destroi(deque *lista);

#endif