#include <stdio.h>

int fib(int k){

	int i;

	if (k <= 0) return 0;
	if (k == 1) return 1;

	return (fib(k-1)+fib(k-2));
}

int main(){
	int n = 6;
	printf("Fib(%d) = %d\n", n, fib(n));
}