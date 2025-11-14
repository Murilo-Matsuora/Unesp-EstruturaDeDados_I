#include <stdlib.h>
#include <stdio.h>
#define MAX 100

void Inserir(int x, int fila[], int *fim){
    if(*fim==MAX-1){
        printf("Lista cheia.\n");
        return;
    }
    (*fim)++;
    fila[*fim]=x;
}

void Remover(int *elem, int *inicio, int *fim, int fila[]){
    if(*inicio==*fim){
        printf("Lista vazia.\n");
        return;
    }
    *elem=fila[*inicio+1];
    (*inicio)++;
    if(*inicio==*fim){
        *inicio==-1;
        *fim==-1;
    }
}

void Imprimir(int fila[], int ini, int fim){
    for(int i=ini+1; i<=fim; i++){
        printf("%d\n",fila[i]);
    }
}

void Separar(int fila[], int ini, int fim){
    int par[MAX], fim_p=-1;
    int impar[MAX], fim_i=-1;
    for(int j=ini+1; j<=fim; j++){
        if(fila[j]%2==0){
            Inserir(fila[j], par, &fim_p);
        }
        else{
            Inserir(fila[j], impar, &fim_i);
        }
    }
    printf("Pares:\n");
    Imprimir(par, -1, fim_p);
    printf("\nÍmpares:\n");
    Imprimir(impar, -1, fim_i);
}

int main(){
    int fila[MAX];
    int ini=-1, fim=-1;
    Inserir(3, fila, &fim);
    Inserir(1, fila, &fim);
    Inserir(4, fila, &fim);
    Inserir(1, fila, &fim);
    Inserir(5, fila, &fim);
    Inserir(9, fila, &fim);
    Inserir(2, fila, &fim);
    Inserir(6, fila, &fim);
    Separar(fila, ini, fim);
}