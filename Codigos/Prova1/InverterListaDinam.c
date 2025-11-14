#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct no{
    int info;
    struct no *prox;
}No;

No *L = NULL;

void Insere(No **L, int x){
    No *novo = malloc(sizeof(No));
    
    if(*L == NULL){
        (*novo).prox = NULL;
        (*novo).info = x;
        *L = novo;
        return;
    }
    No *aux = *L;
    while(aux->prox!=NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->prox = NULL;
    novo->info = x;
}

No* Inverte(No *L){
    No *e[MAX];
    int i=1;
    e[0]=L;
    while(L != NULL){
        
        L = L->prox;
        e[i] = L;
        i++;
    }
    No *I=NULL;
    i = i-2;
    while(i>=0){
        L = e[i];
        Insere(&I, L->info);
        i--;
    }
    return I;
    

}

void Imprime(No *L){
    while(L != NULL){
        printf("%d\n", L->info);
        L = L->prox;
    }
}

int main(){
    Insere(&L, 5);
    Insere(&L, 4);
    Insere(&L, 3);
    Insere(&L, 1);
    Insere(&L, 8);
    Insere(&L, 7);



    Imprime(L);

    printf("ESPACO\n\n");


    Imprime(Inverte(L));
}