#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct pilha{
    int topo1;
    int topo2;
    int elem[MAX];
}Pilha;

char vazia(Pilha P, char t){
    if(t=='1' && P.topo1 == -1 ){
        return 'V';
    }
    if(t=='2' && P.topo2 == MAX ){
        return 'V';
    }
    return 'F';
}

char cheia(Pilha P){
    if(P.topo1 == P.topo2-1){
        return 'V';
    }
    else{
        return 'F';
    }
}

void empilha(Pilha *P, int x){
    if(cheia(*P) == 'V'){
        printf("A lista está cheia.\n");
        return;
    }
    P->topo1+=1;
    P->elem[P->topo1]=x;
    P->topo2-=1;
    P->elem[P->topo2]=x;
}

void desempilha(Pilha *P){
    if(vazia(*P, '1') == 'V'){
        printf("A lista 1 está vazia.\n");
        return;
    }
    if(vazia(*P, '2') == 'V'){
        printf("A lista 2 está vazia.\n");
        return;
    }
    P->topo1-=1;
    P->topo2+=1;
}

void imprime(Pilha P){
    if(vazia(P, '1') == 'F'){
        printf("lista 1:\n");
        for(int topo=0; topo<=P.topo1; topo++){
            printf("%d\n",P.elem[topo]);
        }
    }
    else{
        printf("Lista 1 está vazia.\n");
    }
    printf("\n");
    if(vazia(P, '2') == 'F'){
        printf("lista 2:\n");
        for(int topo=MAX-1; topo>=P.topo2; topo--){
            printf("%d\n",P.elem[topo]);
        }
    }
    else{
        printf("Lista 2 está vazia.\n");
    }

}

int main(){
    Pilha P;
    P.topo1 = -1;
    P.topo2 = MAX;
    int x, pag=1;
    char rep = 's';

    do{
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- pág.: %d\n",pag);
        printf("Qual operação deseja realizar?:\n  - Empilhar: e\n  - Desempilhar: d\n  - Imprimir: i\n  - Sair: s\n");
        scanf(" %c",&rep);
        if(rep == 'e'){
            printf("Qual elemento deseja inserir?: ");
            scanf("%d",&x);
            empilha(&P, x);
        }
        if(rep == 'd'){
            desempilha(&P);
        }
        if(rep == 'i'){
            imprime(P);
        }
        
        pag++;
    }while(rep!='s');

    return 0;
}