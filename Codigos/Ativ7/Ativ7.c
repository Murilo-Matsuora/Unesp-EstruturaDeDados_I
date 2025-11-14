#include <stdlib.h>
#include <stdio.h>

struct arv{
    struct arv *dir;
    struct arv *esq;
    int info;
};

void insere(struct arv **atual, int elem)
{
    if (*atual == NULL)
    {
        *atual = (struct arv *)malloc(sizeof(struct arv));
        if (!(*atual))
        {
            printf("sem memória\n");
            exit(0);
        }
        else
        { /* cria o nó */
            (*atual)->info = elem;
            (*atual)->esq = NULL;
            (*atual)->dir = NULL;
            return;
        }
    }
    else
    { /* escolhe a subarvore */
        if (elem < (*atual)->info)
            insere(&(*atual)->esq, elem);
        else
            insere(&(*atual)->dir, elem);
    }
}

void print_tree(struct arv *r, int c)
{
    int i;
    if (!r)
        return;
    print_tree(r->dir, c + 1);
    for (i = 0; i < 2*c; ++i)
        printf(" ");
    printf("%d\n", r->info);
    print_tree(r->esq, c + 1);
}

void SomaNos(struct arv *r, int* soma){
    if(!r)
        return;
    SomaNos(r->dir, soma);
    SomaNos(r->esq, soma);
    *soma+=r->info;
}

void liberaArv(struct arv* r){
    if(!r)
        return;
    liberaArv(r->dir);
    liberaArv(r->esq);
    free(r);
}

int main(){
    struct arv *raiz = NULL;
    
    insere(&raiz, 30);
    insere(&raiz, 20);
    insere(&raiz, 10);
    insere(&raiz, 70);
    insere(&raiz, 40);
    insere(&raiz, 90);
    insere(&raiz, 50);
    insere(&raiz, 60);
    insere(&raiz, 80);
    
    print_tree(raiz, 0);
    int soma = 0;

    SomaNos(raiz,&soma);

    printf("\n\nSoma de tudo: %d\n\n",soma);

    liberaArv(raiz);

}