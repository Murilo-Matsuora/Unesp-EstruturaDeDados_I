#include <stdlib.h>
#include <stdio.h>
#define MAX 10
#define MAX2 (2*MAX+1)

void inserefc(int x, int filac[], int *fim, int inicio){
    if((*fim + 1)%(MAX2) == inicio){
        printf("Overflow.\n");
    }
    else{
        *fim = (*fim+1)%(MAX2);
        filac[*fim]=x;
    }
}

void CircularOrdenada(int F1[], int ini1, int fim1, int F2[], int ini2, int fim2){
    int Fila3[(MAX2)];
    int ini3 = 0, fim3 = 0;

    while(ini1 != fim1 && ini2 != fim2){
        if(F1[ini1+1]<=F2[ini2+1]){
            inserefc(F1[ini1+1], Fila3, &fim3, ini3);
            ini1++;
        }
        else{
            inserefc(F2[ini2+1], Fila3, &fim3, ini3);
            ini2++;
        }
    }
    while(ini1!=fim1){
        inserefc(F1[ini1+1], Fila3, &fim3, ini3);
        ini1++;
    }
    while(ini2!=fim2){
        inserefc(F2[ini1+1], Fila3, &fim3, ini3);
        ini2++;
    }
    for(int i=ini3+1; i!=(fim3+1)%(MAX2); i=(i+1)%(MAX2)){
        printf("%d\n",Fila3[i]);
    }

}

int main(){
    int Fila1[MAX]; //= { 1, 3, 5, 7, 9, 11, 13 ,15, 17, 19};
    int inicio1 = -1, fim1 = -1;
    while(fim1<MAX-1){
        fim1++;
        Fila1[fim1]=2*fim1+1;
    }
    int Fila2[MAX]; //= {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int inicio2 = -1, fim2 = -1;
    while(fim2<MAX-1){
        fim2++;
        Fila2[fim2]=2*fim2;
    }

    CircularOrdenada(Fila1, inicio1, fim1, Fila2, inicio2, fim2);
}