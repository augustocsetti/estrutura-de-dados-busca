#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100


void quick_sort(int* A, int p, int r){
    if(p >= r)
        return;
    else{
        int q;
        q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}


int partition(int* A, int p, int r){
    int pivot = A[r];
    int i = (p - 1), temp;

    for (int j = p; j <= r- 1; j++){
        if (A[j] <= pivot){
            i++;
            temp = A[i]; A[i] = A[j]; A[j] = temp;
        }
    }
    temp = A[i+1]; A[i+1] = A[r]; A[r] = temp;
    return (i + 1);
}


void print(int* A, int tam){
    printf("Vetor = ( ");
    for(int i = 0; i < tam; i++)
        printf("%d ", A[i]);
    printf(")\n");
}


int main(){
    int *A;

    //Preenchendo vetor
    A = (int*)malloc(MAX*sizeof(int));
    for(int i = 0; i < MAX; i++)
        A[i] = MAX - i;

    print(A, MAX);
    quick_sort(A, 0, MAX-1);
    print(A, MAX);

    free(A);
    return 0;
}
