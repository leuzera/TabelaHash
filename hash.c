/*
 * hash.c
 * 
 * Copyright 2014 Leonardo Moraes Fleury <fleuryleomoraes@gmail.com>
 * 				  Pedro Minaré 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <string.h>

#define N 16 // tamanho da chave (string)	
	
typedef char TChave[N];	
	
typedef struct {	
	TChave chave;	
} TItem;	
	
typedef struct celula {	
	struct celula *pProx;	
	TItem item;	
} TCelula;	
	
typedef struct {	
	TCelula *pPrimeiro, *pUltimo;	
} TLista;

typedef struct {	
	int n; // numero de itens na hash	
	int nro_listas; // tamanho do array de listas	
	int nro_pesos; // tamanho do array de pesos	
	int *p; // array de pesos	
	TLista *v; // array de listas	
} THash;	

int TransPalavras(char *chave, int p[], int m)‫‏‬ { 	
	int i;	
	unsigned int soma = 0; 	
	int comp = strlen(chave);	
	
	for (i = 0; i < comp; i++)‫	‏‬
		soma += (unsigned int) chave[i] * p[i];	
	
	return (soma % m);	
}
	
void GeraPesos(int p[], int n) {	
	int i;	
	srand(time(NULL));	
	for (i = 0; i < n; i++)	
	p[i] = 1 + (int) (10000.0*rand() / RAND_MAX);	
}	
void Inicia(THash *hash, int nro_listas, int nro_pesos) { 	
	int i;	
	hash->n = 0;	
	hash->nro_listas = nro_listas;	
	hash->nro_pesos = nro_pesos;	
	
	// inicializando as listas	
	hash->v = (TLista*) malloc(sizeof(TLista) * nro_listas);	
	for (i = 0; i < nro_listas; i++) 	
	TLista_Inicia(&hash->v[i]);	
	
	// inicializando os pesos	
	hash->p = (int*) malloc(sizeof(int) * nro_pesos);	
	for (i = 0; i < nro_pesos; i++)	
	hash->p[i] = rand() % 100000;	
}
TCelula *PesquisaCelula(THash *hash, TChave chave) {	
	int i = THash_H(hash, chave);	
	TCelula *aux;	
	
	if (TLista_EhVazia(&hash->v[i]))	
		return NULL; // pesquisa sem sucesso	
	
		aux = hash->v[i].pPrimeiro;	
	while (aux->pProx->pProx != NULL && strcmp(chave, aux->pProx->item.chave) != 0)	
		aux = aux->pProx;
	
	if (!strncmp(chave, aux->pProx->item.chave, sizeof(TChave)))	
		return aux;	

	else	
		return NULL; // pesquisa sem sucesso	
}

int h(char *chave, int p[], int m)‫‏‬ { 	
	int i;	
	unsigned int soma = 0; 	
	int comp = strlen(chave);	
		
	for (i = 0; i < comp; i++)‫	‏‬
		soma += (unsigned int) chave[i] * p[i];	
		
	return (soma % m);	
}
int main(int argc, char **argv)
{	
	void Inicia(THash *hash, int nro_listas, int nro_pesos);	
	int THash_H(THash *hash, TChave chave);	
	int Pesquisa(THash *hash, TChave chave, TItem *x);	
	TCelula *PesquisaCelula(THash *hash, TChave chave);	
	return 0;
}

