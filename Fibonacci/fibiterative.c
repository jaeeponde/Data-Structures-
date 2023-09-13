#include <stdio.h>

int fib(int k){

	int i, f0 = 0, f1 = 1, oneback, twoback, present;
	twoback = f0;
	oneback = f1;

	if (k <= 0) return f0;
	if (k == 1) return f1;

	for (i = 2; i <= k; i++){
		present = oneback + twoback;
		twoback = oneback;
		oneback = present;
	}

	return present;
}

int main(){

	int n = 6;

	printf("Fib(%d) = %d\n", n, fib(n));
}
