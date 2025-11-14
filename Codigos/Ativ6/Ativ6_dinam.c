#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

void Inserir(int x, No **inicio, No **fim){
    struct no *aux;
    aux = (No*)malloc(sizeof(No));
    aux->info=x;
    aux->prox=NULL;
    if(!(*fim)){
        *inicio = aux;
    }
    else{
        (*fim)->prox=aux;
    }
    *fim=aux;
}

void Imprimir(No *ini){
    for(No* aux=ini; aux!=NULL; aux=aux->prox){
        printf("%d\n",aux->info);
    }
}

void Separar(No *ini, No *fim){
    No *ini_p = NULL, *fim_p = NULL, *ini_i = NULL, *fim_i = NULL;
    for(No *aux = ini; aux!=NULL; aux=aux->prox){
        if(aux->info%2==0){
            Inserir(aux->info, &ini_p, &fim_p);
        }
        else{
            Inserir(aux->info, &ini_i, &fim_i);
        }
    }
    printf("Pares:\n");
    Imprimir(ini_p);
    printf("\nÍmpares:\n");
    Imprimir(ini_i);
}
void Liberar(No *ini){
    No *aux = ini;
    while(ini!=NULL){
        aux = ini;
        ini = ini->prox;
        free(aux);
    }
}

int main(){
    No *inicio, *fim;
    inicio = NULL;
    fim = NULL;

    Inserir(3, &inicio, &fim);
    Inserir(1, &inicio, &fim);
    Inserir(4, &inicio, &fim);
    Inserir(1, &inicio, &fim);
    Inserir(5, &inicio, &fim);
    Inserir(9, &inicio, &fim);
    Inserir(2, &inicio, &fim);
    Inserir(6, &inicio, &fim);
    Separar(inicio, fim);
    Liberar(inicio);
}