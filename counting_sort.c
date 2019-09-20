#include <stdio.h>
#include <stdlib.h>
#define MAX 7

void couting_sort(int* A, int TAM){

    int *AUX, *C;
    int i, maior = 0;

    AUX = (int*) malloc(MAX*sizeof(int));

    //define tamanho de C
    for(i = 0; i < TAM; i++){
        if(A[i] > maior)
            maior = A[i];
    }
    maior += 1;
    C = (int*) calloc(maior,sizeof(int));

    //conta elementos
    for(i = 0; i < TAM; i++){
        C[A[i]]++;
    }

    //contando índices
    for(i = 1; i < maior; i++){
        C[i] += C[i-1];
    }

    //preenechendo C
    for(i = TAM-1; i >= 0; i--){
        AUX[C[A[i]]-1] += A[i];
        C[A[i]]--;
    }

    for(int i = 0; i < TAM; i++)
        A[i] = AUX[i];

    free(AUX);
    free(C);
}


void print_vec(int* A, int TAM){
    printf("Vec : ( ");
    for(int i = 0; i < TAM; i++)
        printf("%d ", A[i]);
    printf(")\n");
}


int main(){

    int V[MAX] = {1, 2, 5, 2, 0, 3, 1};

    //V = (int*) malloc(MAX*sizeof(int));
    //V = {1, 2, 5, 2, 0, 3, 1};

    print_vec(V, MAX);
    couting_sort(V, MAX);
    print_vec(V, MAX);

    //free(V);
    return 0;
}