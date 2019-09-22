#include<stdio.h>
#define TAM 4

void insertionSort( int A[], int n){
    int i, j, x;
    for (j = 1; j < n; j++){
        x = A[j];
        i = j - 1;
        while( (i >= 0) && (A[i] > x)){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1]=x;
    }
}


int main(int argc, char const *argv[]){

    int A[TAM] = {7, 9, 6, 1};

    insertionSort(A, TAM);

    for(int i = 0; i < TAM; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}
