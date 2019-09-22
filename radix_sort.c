#include <stdio.h>
#include <stdlib.h>
#define MAX 7


void radixSort(int* A, int TAM){

    int maior, exp, i;
    
    //define numero de casas a interar
    for (i = 0; i < TAM; i++)
        if(i == 0)
            maior = A[i];
        else
            if(A[i] > maior)
                maior = A[i];

    for (exp = 1; maior / exp > 1; exp *= 10)
        countingSort(A, TAM, exp);
}


void countingSort(int* A, int TAM, int exp){

    int *AUX, *C;
    int i, maior = 0;

    AUX = (int*) malloc(TAM*sizeof(int));
    C = (int*) calloc(10,sizeof(int));

    //conta elementos
    for(i = 0; i < TAM; i++){
        C[(A[i] / exp) % 10]++;
    }

    //contando índices
    for(i = 1; i < 10; i++)
        C[i] += C[i-1];

    //preenechendo C
    for(i = TAM-1; i >= 0; i--)
        AUX[--C[(A[i] / exp) % 10]] = A[i];

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

    int V[MAX] = {329, 457, 657, 839, 436, 720, 355};

    print_vec(V, MAX);
    radixSort(V, MAX);
    print_vec(V, MAX);

    return 0;
}