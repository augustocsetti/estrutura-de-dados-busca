#include<stdio.h>

int found(int* v, int num, int tam){

	int c;
	for(c=0; c<tam; c++){
		if(num==v[c])
			return(c);
	}
	return(-1);
}

int main(){

	int vec[5] = {1,1,3,1,5};
	int c; 
	printf("%d\n", found(vec, 5, 5));
	return 0;
}
