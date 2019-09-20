#include<stdio.h>

int tabela[9] = {0,1,5,8,9,10,17,17,20};

int corte(int k){
	if(k<=8)
		return(tabela[k]);
	else{
		int r, max = 0, temp;
		for (r=0; r<k; r++){
			temp = tabela[r] + corte(k-1);
			if (temp>max)
				max = temp;
		}
	}
}


int main(){

	int valor, n = 9;

	printf("%d\n", corte(n));

return 0;
}
