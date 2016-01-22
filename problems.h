#pragma once
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class P {
	/*
	Problem  -
	Author: Peter Forgacs <peter.forgacs3@gmail.com>
	Date:

	Problem Description:


	Possible Improvements:

	*/
public:
	P() {

	}
};

class P9 {
	/*
	Problem 9 - Special Pythagorean triplet

	Problem Description:
	
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a2 + b2 = c2
	For example, 32 + 42 = 9 + 16 = 25 = 52.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.

	Possible Improvements:

	*/
public:
	P9() {
		int c = 1000;
		// Rounded
		int max_c = 1000 - 1;

		clock_t runtime = clock();
		for (int c = max_c; c > 1; --c) {
			for (int b = 1; b < max_c; ++b) {
				for (int a = 0; a < max_c - b; ++a) {
					if (a + b + c == 1000 && a < b && b < c) {
						if (a*a + b*b == c*c) {
							std::cout << "a " << a << std::endl;
							std::cout << "b " << b << std::endl;
							std::cout << "c " << c << std::endl;
							goto end;
						}
					}
				}
			}
		}

	end:
		printf("Full runtime: %.2fs\n", (double)(clock() - runtime) / CLOCKS_PER_SEC);
		system("pause");
	}
};

class P8 {
	/*
	Problem 8 - Largest Product in a series

	Problem Description:

	The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

	73167176531330624919225119674426574742355349194934
	96983520312774506326239578318016984801869478851843
	85861560789112949495459501737958331952853208805511
	12540698747158523863050715693290963295227443043557
	66896648950445244523161731856403098711121722383113
	62229893423380308135336276614282806444486645238749
	30358907296290491560440772390713810515859307960866
	70172427121883998797908792274921901699720888093776
	65727333001053367881220235421809751254540594752243
	52584907711670556013604839586446706324415722155397
	53697817977846174064955149290862569321978468622482
	83972241375657056057490261407972968652414535100474
	82166370484403199890008895243450658541227588666881
	16427171479924442928230863465674813919123162824586
	17866458359124566529476545682848912883142607690042
	24219022671055626321111109370544217506941658960408
	07198403850962455444362981230987879927244284909188
	84580156166097919133875499200524063689912560717606
	05886116467109405077541002256983155200055935729725
	71636269561882670428252483600823257530420752963450

	Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

	Possible Improvements:

	*/
public:
	const int p8_ADJECENT_NUM = 13 - 1;

	P8() {
		// Reading in the number from a file
		vector<int>numbers;
		string line;
		ifstream myfile{ "Database/p8.txt" };

		while (getline(myfile, line)) {
			for (char i : line) {
				// Turning char into int
				int num = i - '0';
				// Pushing it to a vector
				numbers.push_back(num);
			}
		}

		// Checking the Largest product
		unsigned long long int buf = 0;
		unsigned long long int max = 0;

		for (int i = 0; i < numbers.size() - p8_ADJECENT_NUM; ++i) {
			for (int j = i; j < i + p8_ADJECENT_NUM; j++) {
				// At the first loop
				if (j == i) { buf = numbers.at(j)*numbers.at(j + 1); }
				//All other loops 
				else { buf *= numbers.at(j + 1); }
			}
			// Get the bigges
			if (buf > max) { max = buf; }
		}

		cout << max << endl;

		system("pause");

	}
};

class P7 {
	/*
	Problem 7 - 10001st prime

	Problem Description:
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
	What is the 10 001st prime number?

	Possible Improvements:
	Increment j by two because even numbers cant be primes.
	*/
public:
	P7(){

	clock_t runtime = clock();
	int last_prime;
	int treshold = 10001;
	int primes_found = 0;

	int i = 2;
	while (primes_found != treshold) {
		int j = 2;
		while (j <= i) {
			if (i%j == 0 && i != j) {
				//std::cout << "Not a prime " << i << std::endl;
				break;
			}
			else if (j == i) {
				++primes_found;
				last_prime = i;
			}

			j >= 3 ? j += 2 : ++j;
		}
		++i;
	}
	std::cout << "Prime " << last_prime << std::endl;
	printf("Full runtime: %.2fs\n", (double)(clock() - runtime) / CLOCKS_PER_SEC);
	system("pause");
	}
};

class P6 {
	/*
	Problem 6  - Sum Square Difference
	Date: 2016

	Problem Description:
	The sum of the squares of the first ten natural numbers is,

	12 + 22 + ... + 102 = 385
	The square of the sum of the first ten natural numbers is,

	(1 + 2 + ... + 10)2 = 552 = 3025
	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

	Possible Improvements:

	*/
public:
	P6() {
		float sum_of_squares = get_sum_of_squares(100);
		float square_of_sum = get_square_of_sum(100);
		int result = square_of_sum - sum_of_squares;
		cout << "sum of squares " << sum_of_squares << endl;
		cout << "square of sum " << square_of_sum << endl;
		cout << "result " << result << endl;
		system("pause");
	}

	float P6::get_sum_of_squares(int num) {
		float val = 0;
		for (num; num != 0; num--) {
			val += pow(num, 2);
		}
		return val;
	}

	float P6::get_square_of_sum(int num) {
		float val = 0;
		for (int i = 1; i <= num; i++) {
			val += i;
		}
		val = pow(val, 2);
		return val;
	}

};

class P5 {
	/*
	Problem  -
	Author: Peter Forgacs <peter.forgacs3@gmail.com>
	Date:

	Problem Description:


	Possible Improvements:

	*/
public:
	P5() {

	}
};

class P4 {
	/*
	Problem  -
	Author: Peter Forgacs <peter.forgacs3@gmail.com>
	Date:

	Problem Description:


	Possible Improvements:

	*/
public:
	P4() {

	}
};

class P3 {
	/*
	Problem 3 - Largest Prime Factor

	Problem Description:
	
	The prime factors of 13195 are 5, 7, 13 and 29.
	What is the largest prime factor of the number 600851475143 ?

	Possible Improvements:

	*/
public:
	P3() {
		unsigned long long int num = 600851475143;
		std::vector<int> prime_factors;

		for (unsigned long long int i = 3; i < sqrt(num); i += 2) {
			std::cout << i << std::endl;
			if (num%i == 0) {
				if (is_prime(i)) {
					std::cout << i << std::endl;
					prime_factors.push_back(i);
				}
			}
		}

		for (int i : prime_factors) {
			std::cout << i << std::endl;
		}

		system("pause");
	}

	bool is_prime(unsigned long long int i) {
		for (long int j = 2; j < i; ++j) {
			if (i%j == 0) {
				return false;
			}
		}
		return true;
	}
};

class P2 {
	/*
	Problem  -
	Author: Peter Forgacs <peter.forgacs3@gmail.com>
	Date:

	Problem Description:


	Possible Improvements:

	*/
public:
	P2() {

	}
};

class P1 {
	/*
	Problem  -
	Author: Peter Forgacs <peter.forgacs3@gmail.com>
	Date:

	Problem Description:


	Possible Improvements:

	*/
public:
	P1() {

	}
};