#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct no{
    int info;
    int prox;
}No;

int Usar(int dispo[]){
    int aux, i=0;
    while(dispo[i]==-1){
        if(i==MAX){
            printf("Lista cheia.\n");
            return -1;
        }
        i++;
    }
    
    aux=dispo[i];
    dispo[i]=-1;
    return aux;
}

void Devolver(int dispo[], int e){
    int i=0;
    while(i!=MAX){
        if(dispo[i]==-1){
            dispo[i]=e;
            return;
        }
        i++;
    }
}

void Insere(No Lista[], int *L, int dispo[], int x){
    int aux = Usar(dispo);
    if(aux==-1){
        printf("Lista cheia.\n");
        return;
    }
    if(*L == -1){
        *L=aux;
        Lista[aux].info = x;
        Lista[aux].prox = -1;
        return;
    }
    int i=*L, ant=-1;
    while(x >= Lista[i].info && i!=-1){
        ant=i;
        i=Lista[i].prox;
    }
    if(i==-1){
        Lista[ant].prox = aux;
        Lista[aux].info = x;
        Lista[aux].prox = -1;
        return;
    }
    else{
        if(ant == -1){
            Lista[aux].info = x;
            Lista[aux].prox = *L;
            *L=aux;
        }
        else{
            Lista[aux].info = x;
            Lista[aux].prox = Lista[ant].prox;
            Lista[ant].prox = aux;
        }
    }           
    
}

void Remove(No Lista[], int L, int dispo[], int vi, int vf){
    if(vf<vi){
        printf("vf deve ser maior que vi.\n");
        return;
    }
    int i=L, j=L, aux=-1, ant=-1;
    while(Lista[i].info<vi){
        ant = i;
        i=Lista[i].prox;
    }
    while(Lista[j].info<=vf && j!=-1/*Lista[Lista[j].prox].info < vf*/){
        j=Lista[j].prox;
    }
    
    while(j!=i){
        Lista[ant].prox=Lista[i].prox;
        Lista[i].prox=-1;
        Devolver(dispo, i);
        
        i=Lista[ant].prox;
    }
}

void Imprime(No Lista[], int L){
    while(Lista[L].prox!=-1){
        printf("%d\n", Lista[L].info);
        L=Lista[L].prox;
    }
    printf("%d\n", Lista[L].info);
}

int main(){
    No Lista[MAX];
    int L = -1;
    int dispo[MAX+1];
    for(int i=0; i<MAX; i++){
        dispo[i]=i;
    }
    dispo[MAX]=-1;

    Insere(Lista, &L, dispo, 3);
    Insere(Lista, &L, dispo, 1);
    Insere(Lista, &L, dispo, 4);
    Insere(Lista, &L, dispo, 1);
    Insere(Lista, &L, dispo, 5);
    Insere(Lista, &L, dispo, 9);
    
    Imprime(Lista, L);

    //------
    printf("\n");
    Remove(Lista, L, dispo, 2, 6);

    Imprime(Lista, L);

    //------
    printf("\n------\n");
    Insere(Lista, &L, dispo, 2);
    Insere(Lista, &L, dispo, 6);
    Insere(Lista, &L, dispo, 0);
    Insere(Lista, &L, dispo, 7);
    Insere(Lista, &L, dispo, 0);

    Imprime(Lista, L);
    //------
    printf("\n");

    Remove(Lista, L, dispo, 1, 6);
    Imprime(Lista, L);


}