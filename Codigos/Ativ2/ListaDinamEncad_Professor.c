#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct no{
    int info;
    struct no *prox;
};

typedef struct no No;

int tamLista(No *Lista){
    No *aux = Lista;
    int i=0;
    while(aux!=NULL){
        aux=aux->prox;
        i++;
    }
    return i;
}

No* toLast(No *Lista){
    No *aux=Lista;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    return aux;
}

No* to_n(No *Lista, int n){
    No *aux=Lista;
    if(tamLista(Lista)<n){
        printf("n maior que lista; %d > %d.\n",n,tamLista(Lista));
        return(Lista);
    }
    for(int i=0; i<n; i++){
        aux=aux->prox;
    }
    return aux;

}

void ImprimeLista(No *Lista){
    No *p = Lista;
    printf("A lista eh:\n");
    while(p!=NULL){
        printf("[  %d  ]\n",p->info);
        p=p->prox;
    }
}

void InsereInic(No **Lista, int x){
    No *novo; 
    novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = *Lista;
    *Lista=novo;
}

void InsereEm(No *Lista, int n, int x){
    if(tamLista(Lista)<n){
        printf("n maior que lista; %d > %d.\n",n,tamLista(Lista));
        return;
    }
    if(n==0){
        printf("Não pode ser 0.\n");
        return;
    }
    No *novo; 
    novo = (No*)malloc(sizeof(No));
    
    Lista=to_n(Lista, n-1);
    novo->info=x;
    novo->prox=Lista->prox;
    Lista->prox=novo;
}

void InsereFim(No *Lista, int x){
    No *novo; 
    novo = (No*)malloc(sizeof(No));
    novo->info=x;
    novo->prox=NULL;
    Lista=toLast(Lista);
    Lista->prox=novo;
}

void InsereOrd(No *Lista, int x){
    if(x<Lista->info){
        printf("O valor %d não pode ser inserido pois deve ser maior ou igual a %d\n", x, Lista->info);
        return;
    }
    No *novo, *ant;
    
    novo = (No*)malloc(sizeof(No));
    if(novo==NULL){
        printf("Falha na alocação de memória.\n");
        return;
    }
    while(Lista!=NULL && x>=Lista->info){
            ant=Lista;
            Lista=Lista->prox;
    }

    if(Lista==NULL){
        ant->prox = novo;
        novo->prox = Lista;
        
        novo->info = x;
    }
    else{
        novo->prox = Lista;
        ant->prox = novo;
        novo->info = x;
    }
    
}

void Libera(No *L){
    No *ant;
    int tam = tamLista(L);
    for(int i=0; i<(tam-1); i++){
        ant=L;
        L=L->prox;
        free(ant);
    }
    free(L);
}

int main(){
    No *L;
    L = (No*)malloc(sizeof(No));
    L=NULL;
    int x=0;
    char again[]="sim";
    printf("Qual o elemento incial?: ");
    scanf("%d",&x);
    InsereInic(&L,x);
    printf("\nDeseja continuar? (Digite 'sim' ou 'nao'): ");
    scanf("%s",again);
    while(strcmp("sim", again)==0 || again[0]=='s'){
        printf("Qual elemento para ser inserido em ordem crescente?: ");
        scanf("%d",&x);
        InsereOrd(L, x);
        printf("\nDeseja continuar? (Digite 'sim' ou 's' caso queira): ");
        scanf("%s",again);
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    ImprimeLista(L);
    Libera(L);
    
    return 0;
}
