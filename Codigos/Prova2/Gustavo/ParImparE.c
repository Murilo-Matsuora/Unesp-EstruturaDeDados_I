#include <stdio.h>

#define MAX 100

void inserir(int x, int fila[], int *fim)
{
    if (*fim == MAX - 1)
        printf("Nao cola inserir nada fi");
    else
    {
        (*fim)++;
        fila[*fim] = x;
    }
}

void adicionaParouImpar(int fila[], int inicio, int fim)
{
    int filaPar[MAX];
    int inicioPar = -1, fimPar = -1;

    int filaImpar[MAX];
    int inicioImpar = -1, fimImpar = -1;

    for (int i = inicio + 1; i <= fim; i++)
    {
        if (fila[i] % 2 == 0)
            inserir(fila[i], filaPar, &fimPar);
        else
            inserir(fila[i], filaImpar, &fimImpar);
    }
    printf("Fila de elementos pares: ");
    for (int j = 0; j <= fimPar; j++)
        printf("%d\t", filaPar[j]);
    printf("\n");

    printf("Fila de elementos impares: ");
    for (int j = 0; j <= fimImpar; j++)
        printf("%d\t", filaImpar[j]);
    printf("\n");
}

int main()
{
    int inicio = -1, fim = -1;
    int fila[MAX];

    inserir(2, fila, &fim);
    inserir(3, fila, &fim);
    inserir(4, fila, &fim);
    inserir(7, fila, &fim);
    inserir(12, fila, &fim);
    inserir(13, fila, &fim);
    inserir(17, fila, &fim);
    inserir(19, fila, &fim);
    inserir(23, fila, &fim);

    adicionaParouImpar(fila, inicio, fim);

    return 0;
}