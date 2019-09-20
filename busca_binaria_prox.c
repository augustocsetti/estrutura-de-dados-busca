#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

unsigned long int found(unsigned long int* v, unsigned long int num, unsigned long int init, unsigned long int fim){

	unsigned long int c;

	printf("init: %lu\n", init);
	printf("fim: %lu\n", fim);

	if(init<=fim){

		c = floor((init+fim)/2.0);

		if(v[c]==num)
			return(v[c]);
		else{
			if(v[c]>num)
				return found(v, num, init, c-1);
			else
				return found(v, num, c+1, fim);
		}
	}
	else{
		printf("Número não consta na lista. Retornado o mais próximo.\n");
		printf("x: %lu\n", num);
		printf("init: %lu\n", init);
		printf("fim: %lu\n", fim);

		return(v[fim]);
	}
}

int main(){

	
	unsigned long int *vec, cont;
	int x = 209;

	vec = (unsigned long int*) malloc(MAX*sizeof(unsigned long int));
	for(cont = 0; cont < MAX; cont++){
		vec[cont] = cont*2+10;
		printf("%lu\n", vec[cont]);
	}

	printf("%lu\n", found(vec, x, 0, MAX));

	free(vec);
	return 0;
}
