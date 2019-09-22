#include<stdio.h>

int rec = 0;

int max(int A, int B){
	if(A > B)
		return A;
	else
		return B;
}


int cutRodBottomUp(int* p, int n){
	int i, q = -1;
	rec++;
	if (n == 0)
		return 0;
	for (i = 1; i <= n; i++){
		q = max(q, p[i] + cutRod(p, n-i));
	}
	return q;
}


int main(){

	int p[9] = {0,1,5,8,9,10,17,17,20};
	int n = 9;

	printf("Valor = %d\n", cutRodBottomUp(p, n));
	printf("Recursões = %d", rec);

return 0;
}