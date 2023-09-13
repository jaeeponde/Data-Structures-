#include <stdio.h>

//recursive factorial 
int factrec (int k){
	int i, prod = 1;

	if (k <= 1) return 1;

	else return (k*factrec(k-1));
}

void factrecans(){
	int n = 5;
	printf("%d\n", factrec(n));
}

//iterative factorial using a function
int factit(int k){

	int i, prod = 1;

	for (i = 2; i <= k; i++)
		prod = prod*i;

	return prod;
}

void factitans(){

	int n = 5;

	printf("%d\n", factit(n));
}

