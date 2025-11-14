#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    int num;
    int clas;
    struct Aluno* next;

}Aluno;

void InsereInic(Aluno **Lista, int num, int clas){
    Aluno *novo; 
    novo = (Aluno*)malloc(sizeof(Aluno));
    novo->num = num;
    novo->clas = clas;
    novo->next = *Lista;
    *Lista = novo;
}

void InsereOrd(Aluno **Lista){
    int num, clas;
    printf("Digite o número do aluno: ");
        scanf(" %d",&num);
    printf("Digite a classificação do aluno: ");
        scanf(" %d",&clas);
    Aluno *novo;
    novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo == NULL){
        printf("Falha na alocação de memória.\n");
        return;
    }
    Aluno *first = *Lista;
    if( (*Lista)==NULL || num<(*Lista)->num){
        InsereInic(Lista,num,clas);
        return;
    }
    Aluno *ant=NULL;
    while((*Lista)!=NULL && num>=(*Lista)->num){
        ant = (*Lista);
        (*Lista) = (*Lista)->next;
    }
    if((*Lista)==NULL){
        ant->next = novo;
        novo->next = (*Lista);
        novo->num = num;
        novo->clas = clas;
        *Lista = first;
        
        return;
    }
    else{
        novo->next = (*Lista);
        ant->next = novo;
        novo->num = num;
        novo->clas = clas;
        *Lista = first;
        return;
    }
}

void RemoveAluno(Aluno **L){
    int num;
    printf("Qual número do aluno quem deseja remover?: ");
    scanf(" %d",&num);
    Aluno* aux = *L;
    Aluno* ant=NULL;
    while(aux->num!=num){
        ant=aux;
        aux=aux->next;
    }
    if(aux==NULL){
        printf("O número %d não foi encontrado.\n",num);
    }
    if(ant==NULL){
        if(aux->next==NULL){
            *L = NULL;
            free(aux);
        }
        else{
            *L = aux->next;
            free(aux);
        }
    }
    else{
        if(aux->next==NULL){
            ant->next = NULL;
            free(aux);
        }
        else{
            ant->next=aux->next;
            free(aux);
        }
        
    }
}

void ImprimeLista(Aluno *L){
    for(Aluno* i=L; i!=NULL; i=i->next){
        printf("Número: %d\nClassificação: %d\n\n",i->num,i->clas);
    }
}


int main(){
    Aluno *L;
    L = (Aluno*)malloc(sizeof(Aluno));
    L=NULL;
    /*
    int num, clas;
    printf("Digite o número do aluno: ");
        scanf(" %c",num);
    printf("Digite o número do aluno: ");
        scanf(" %c",num);  
    */
   InsereOrd(&L);
    char rep;
    do{
        printf("\nQual operação deseja realizar?\n  - Adicionar um aluno: a\n  - Remover um aluno: r\n  - Mostrar todos alunos: t\n  - Fechar programa: n\n");
        scanf(" %c",&rep);
        if(rep == 'a'){
            InsereOrd(&L);
        }
        if(rep == 'r'){
            RemoveAluno(&L);
        }
        if(rep == 't'){
            ImprimeLista(L);
        }
        
    }while(rep != 'n');
}