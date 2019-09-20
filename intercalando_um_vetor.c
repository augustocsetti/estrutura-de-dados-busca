#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 8

void intercala(unsigned long int* V, unsigned long int p, unsigned long int r){

	if(p == r-1)
		return;
	else{
		unsigned long int q = (r+p)/2.0, temp, i;
		unsigned long int mid = ceil((q+p)/2.0);
		
		for(i = mid; i <= q; i++){
			temp = V[i];
			V[i] = V[i+mid-p];
			V[i+mid-p] = temp;
		}
	
		intercala(V, q+1, r);		
		intercala(V, p, q);
	}
}

void imprime(unsigned long int *V){
	unsigned long int cont;
	printf("Vetor: ( ");
	for(cont = 0; cont < MAX; cont++)
		printf("%lu ", V[cont]);
	printf(")\n");
}

int main(){

	unsigned long int *vec, cont;
	vec = (unsigned long int*) malloc(MAX*sizeof(unsigned long int));
	
	unsigned long int vec1[8] = {0,2,4,6,1,3,5,7};

	for(cont = 0; cont < MAX; cont++)
		vec[cont] = cont;

	imprime(vec1);
	intercala(vec1, 0, MAX-1);
	imprime(vec1);

	free(vec);
return 0;
}
