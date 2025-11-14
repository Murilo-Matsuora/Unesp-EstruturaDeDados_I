#include <stdio.h>
#define MAX 8

void inserir(int M[][MAX], int i, int j){
    M[i-1][j-1] = 1;
    M[j-1][i-1] = 1;
}

void imprimir(int M[][MAX]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%d  ", M[i][j]);
        }
        printf("\n");
    }
}

void DFS(int M[][MAX], int visite[], int v) { // v é o nó de partida 
    visite[v] = 1;
    printf("%d \n", v+1); //Mostra quais nós estão sendo visitados.
    for(int i=0; i<8; i++){
        if(M[v][i] == 1 && visite[i] == 0){
            DFS(M, visite, i);
        }
    }
}

int main(){
    int mat_adj[MAX][MAX] = {0};

    inserir(mat_adj, 1, 2);
    inserir(mat_adj, 1, 3);
    inserir(mat_adj, 2, 4);
    inserir(mat_adj, 2, 5);
    inserir(mat_adj, 3, 6);
    inserir(mat_adj, 3, 7);
    inserir(mat_adj, 4, 8);
    inserir(mat_adj, 5, 8);
    inserir(mat_adj, 6, 8);
    inserir(mat_adj, 7, 8);

    int vertices[8] = {0};
    DFS(mat_adj, vertices, 0);

    //imprimir(mat_adj);
}

