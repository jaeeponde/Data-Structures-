#include <stdio.h>

int fact (int k){

	int i, prod = 1;

	for (i = 2; i <= k; i++)
		prod = prod*i;

	return prod;
}

int main(){

	int n = 5;

	printf("%d\n", fact(n));
}
