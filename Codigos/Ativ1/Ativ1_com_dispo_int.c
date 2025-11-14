#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct no{
    int info;
    int prox;
}No;

void Inserir(No Lista[], int *L, int *dispo, int x){
    if(*dispo==-1){
        printf("Lista cheia.\n");
        return;
    }
    int i=*L, ant=-1;
    if(i == -1){ 
        *L = *dispo;
        *dispo = Lista[*dispo].prox;
        Lista[*L].info = x;
        Lista[*L].prox = -1;
        return;
    }
    
    while(x > Lista[i].info && i!=-1){
        ant=i;
        i=Lista[i].prox;
       
    }
    if(ant==-1){//Caso seja o primeiro elemento da lista.
        int aux = Lista[*dispo].prox;
        Lista[*dispo].prox = *L;
        Lista[*dispo].info = x;
        *L = *dispo;
        *dispo = aux;
        return;
    }
    
    if(i == -1){
        int aux = Lista[*dispo].prox;
        Lista[ant].prox = *dispo;
        Lista[*dispo].info = x;
        Lista[*dispo].prox = -1;
        *dispo = aux;
        return;
    }
    Lista[i].prox = Lista[ant].prox;
    Lista[ant].prox = *dispo;
    *dispo = Lista[*dispo].prox;
}



void Imprimir(No Lista[], int L){
    while(L!=-1){
        printf("%d\n",Lista[L].info);
        L = Lista[L].prox;
    }
}

int main(){
    No Lista[MAX];
    for(int i=0; i<MAX; i++){
        Lista[i].prox=i+1;
    }
    Lista[MAX-1].prox=-1;
    int L = -1;
    int dispo = 0;

    //Imprimir(Lista, dispo);


    Inserir(Lista, &L, &dispo, 3);
    Inserir(Lista, &L, &dispo, 1);
    Inserir(Lista, &L, &dispo, 4);
    Inserir(Lista, &L, &dispo, 1);
    Inserir(Lista, &L, &dispo, 5);



    
    
    Imprimir(Lista, L);
    
    return 0;
}
