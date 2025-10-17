#include "lista.h"
/* coloque demais includes aqui */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ------------------- Nao altere estas structs ------------------------- */
struct nodo {
    int chave;
    struct nodo *prox;
};

struct lista {
    struct nodo *ini;
    struct nodo *ptr; /* ponteiro para algum nodo da lista (iterador) */
    int tamanho;

};
/* ---------------------------------------------------------------------- */

struct lista *lista_cria (){
    struct lista *nova_lista = malloc(sizeof(struct lista));
    if(!nova_lista)
        return NULL;
    memset (nova_lista, 0, sizeof(struct lista));
    return nova_lista;
}

void lista_destroi (struct lista **lista){
}

int lista_insere_inicio (struct lista *lista, int chave){
    struct nodo *novo_nodo = malloc(sizeof(struct nodo));
    if((!novo_nodo)||(lista->tamanho = 5))
        return 0;
    novo_nodo->prox = lista->ini;
    novo_nodo->chave = chave;
    lista->ini= novo_nodo;
    lista->tamanho++;
    return 1;
}

int lista_insere_fim (struct lista *lista, int chave){
    int i;
    struct nodo *novo_nodo = malloc(sizeof(struct nodo));
    if((!novo_nodo)||(lista->tamanho = 5))
        return 0;
    lista->ptr=lista->ini;
    for (i = 0; i < lista->tamanho; i++)
        lista->ptr=lista->ptr->prox;
    novo_nodo->prox=lista->ptr->prox;
    novo_nodo->chave=chave;
    lista->tamanho++;
    return 1;
}

int lista_insere_ordenado (struct lista *lista, int chave){
    int i;
    int *ptr;
    struct nodo *novo_nodo = malloc(sizeof(struct nodo));
    if((!novo_nodo)||(lista->tamanho = 5))
        return 0;
    if(lista->ini->chave > chave)
        lista_insere_inicio(lista, chave);
    else{
    lista_inicia_iterador(lista);
    for (i = 0; i < lista->tamanho; i++){
        if (lista->ptr->prox->chave <= chave)
            lista_incrementa_iterador(lista, ptr);
    }
    novo_nodo->prox=lista->ptr->prox;
    novo_nodo->chave=chave;
    lista->tamanho++;
    return 1;
}
}

int lista_remove_inicio (struct lista *lista, int *chave){

}

int lista_remove_fim (struct lista *lista, int *chave){
}

int lista_remove_ordenado (struct lista *lista, int chave){
}

int lista_vazia (struct lista *lista){
    if (lista->tamanho = 0)
        return 1;
    return 0;
}

int lista_tamanho (struct lista *lista){
    int i = lista->tamanho;
    return i;
}

int lista_pertence (struct lista *lista, int chave){
}

void lista_inicia_iterador (struct lista *lista){
    lista->ptr=lista->ini;
}

int lista_incrementa_iterador (struct lista *lista, int *chave){
    lista->ptr=lista->ptr->prox;
    if (lista->ptr = NULL)
        return 0;
    chave = lista->ptr->chave;
    return 1;    
}
