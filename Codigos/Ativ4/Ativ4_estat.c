#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct no{
    char a;
}No;
No Pilha[MAX];
int topo=-1;

void push(No Pilha[], int *topo, char a){
    if(*topo == MAX-1){
        printf("Overflow.\n");
        return;
    }
    else{
        (*topo)++;
        Pilha[*topo].a=a;
    }
}

int pop(No Pilha[], int *topo, char *elem){
    if((*topo)==-1){
        printf("Underflow.\n");
        return 0;
    }
    else{
        *elem=Pilha[*topo].a;
        (*topo)--;
        return 1;
    }
}

int main(){
    char a = 'a';
    char elem;
    int igual=1;
    
    printf("Digite uma linha de a's e b's, com um C no meio. O programa verifica se a parte antes de C é o reverso da que vem depois.\n");
    scanf("%c",&a);
    while(a!='C'){
        push(Pilha, &topo, a);
        scanf("%c",&a);
    }
    while(a!='\n' && igual == 1){
        scanf("%c",&a);
        if(a=='\n'){
            if(topo==-1){
                break;
            }
            else{
                igual=0;
                break;
            }
        }
        igual = pop(Pilha, &topo, &elem);
        if(a!=elem){
            igual = 0;
            break;
        }
    }
    if(igual == 1){
        printf("A sequência é simétrica :D\n");
    }
    else{
        printf("A sequência NÃO é simétrica :(\n");
    }
}