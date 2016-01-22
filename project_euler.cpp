/*
Author: Peter Forgacs <peter.forgacs3@gmail.com>
https://projecteuler.net/about peter.chip
*/
#include <time.h>
#include "problems.h"

int main() {
	clock_t runtime = clock();
	
	// Calling a specific problem 
	P10();
	
	printf("Full runtime: %.2fs\n", (double)(clock() - runtime) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}

