#include <stdio.h>

int fact (int k){
	int i, prod = 1;

	if (k <= 1) return 1;

	else return (k*fact(k-1));
}

int main(){
	int n = 5;
	printf("%d\n", fact(n));
}