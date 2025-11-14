#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char a;
    struct no *next;
}No;
No *topo = NULL;

void push(No **topo, char a){
    No *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    aux->a = a;
    aux->next = *topo;
    *topo = aux;
}

int pop(No **topo, char *elem){
    No *aux;
    if(!(*topo)){
        printf("Underflow.\n");
        return 0;
    }
    else{
        *elem = (*topo)->a;
        aux = *topo;
        *topo = aux->next;
        free(aux);
        return 1;
    }
}

void libera(No *topo){
    if(topo == NULL)
        return;
    No *aux;
    while(topo!= NULL){
        aux=topo;
        topo = topo->next;
        free(aux);
    }
}

int main(){
    char a = 'a';
    char elem;
    int igual=1, teste=1;

    printf("Digite uma linha de a's e b's, com um C no meio. O programa verifica se a parte antes de C é o reverso da que vem depois.\n");
    scanf("%c",&a);
    while(a!='C'){
        push(&topo, a);
        scanf("%c",&a);
    }
    while(igual==1){
        teste = pop(&topo, &elem);
        scanf("%c",&a);
        if(teste == 0){
            break;
        }
        if(a!=elem){
            igual = 0;
            break;
        }
        
        igual = teste;
    }
    free(topo);
    if(igual == 1 && a=='\n'){
        printf("A sequência é simétrica :D\n");
    }
    else{
        printf("A sequência NÃO é simétrica :(\n");
    }
}