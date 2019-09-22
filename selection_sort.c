#include<stdio.h>
#define TAM 4

void selectionSort (int v[], int n){
    int i, j, min, x;
    for (i = 0; i < n-1; ++i){
        min = i;
        for (j = i+1; j < n; ++j)
            if( v[j] < v[min])
                min = j;
            x = v[i];
            v[i] = v[min];
            v[min] = x;
    }
}

int main(int argc, char const *argv[]){

    int A[TAM] = {7, 9, 6, 1};

    selectionSort(A, TAM);

    for(int i = 0; i < TAM; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}
