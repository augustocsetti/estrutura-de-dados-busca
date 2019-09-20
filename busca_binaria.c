#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100000000

unsigned long int found(unsigned long int* v, unsigned long int num, unsigned long int init, unsigned long int fim){

	unsigned long int c;

	if(init<=fim){

		c = floor((init+fim)/2.0);

		if(v[c]==num)
			return(c);
		else{
			if(v[c]>num)
				return found(v, num, init, c-1);
			else
				return found(v, num, c+1, fim);
		}
	}
	else{
		return(-1);
	}
}

int main(){

	
	unsigned long int *vec, cont;
	int x = 10000;

	vec = (unsigned long int*) malloc(MAX*sizeof(unsigned long int));
	for(cont = 0; cont < MAX; cont++)
		vec[cont] = cont;

	printf("%lu\n", found(vec, x, 0, MAX));

	free(vec);
	return 0;
}
