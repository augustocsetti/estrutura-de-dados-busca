#include<stdio.h>
#define TAM 4


void bubbleSort( int v[], int n){
    int i, j, aux;
    int k = n -1 ;
    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1]=aux;
            }
        }
        k--;
    }
}


int main(int argc, char const *argv[]){

    int A[TAM] = {7, 9, 6, 1};

    bubbleSort(A, TAM);

    for(int i = 0; i < TAM; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}