﻿#pragma once
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class P {
	/*
	Problem  -

	Problem Description:


	Possible Improvements:

	*/
public:
	P() {

	}
};

class P11 {
	/*
	Problem 11 - Largest product in a grid

	Problem Description:
	
	In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

	08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
	49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
	81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
	52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
	22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
	24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
	32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
	67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
	24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
	21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
	78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
	16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
	86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
	19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
	04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
	88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
	04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
	20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
	20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
	01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

	The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

	What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

	Possible Improvements:

	Left: at least 4th item in the list -> index 3
	Right: at least 20 - 4 = 17th item in the list -> index 16
	Up: at least 4th row
	Down: max 17th row
	
	Diagonal Up left:    at least 4th row   && at least 4th element in the list
	Diagonal Up Right:   at least 4th row   && at max 17th element in the list
	Diagonal Down left:  at max 17th row    && at least 4th element in the list
	Diagonal Down right: at max 17th row    && at max 17th item

	*/
public:
	const int adjecent_elements = 4;
	const int length_of_rows = 20;
	vector<vector<int>> matrix;
	unsigned long long int biggest_product = 1;
	

	P11() {
		vector<vector<int>> matrix = create_matrix();
		for (int i = 0; i < length_of_rows; ++i) {
			for (int j = 0; j < length_of_rows; ++j) {
		
				 unsigned long long int k = get_directions(i, j);
				 if (biggest_product < k) { biggest_product = k; }
			}
		}
		cout << biggest_product << endl;
	}
		
	vector<vector<int>> create_matrix() {
		// Reading in the numbers into a matrix
		int num;
		ifstream file("Database/p11.txt");
		for (int i = 0; i < length_of_rows; ++i) {
			vector<int> row;
			for (int j = 0; j < length_of_rows; ++j) {
				file >> num;
				row.push_back(num);
			}
			matrix.push_back(row);
		}
		return matrix;
	}
	
	unsigned long long int get_directions(int row, int elem) {

		try {

			vector<int> result;
			result.reserve(8);
		
			int sum_left = 1, sum_up = 1, up_left_diagonal = 1, sum_right = 1, up_right_diagonal = 1, sum_down = 1, down_left_diagonal = 1, down_right_diagonal = 1;

			//TODO Create a general method that handles all the possible sides
			// Left or Up
			if (elem - adjecent_elements >= 0) {
				for (int i = 0; i <= adjecent_elements - 1; ++i) {
					sum_left *= matrix.at(row).at(elem - i);

				}
				result.push_back(sum_left);

				// Diagonal Up left
				if (row - adjecent_elements >= 0) {
					for (int i = 0; i <= adjecent_elements - 1; ++i) {
						up_left_diagonal *= matrix.at(row - i).at(elem - i);
					}
					result.push_back(up_left_diagonal);
				}
			}

			// Up 
			if (row - adjecent_elements >= 0) {
				for (int i = 0; i <= adjecent_elements - 1; ++i) {
					sum_up *= matrix.at(row - i).at(elem);
				}
				result.push_back(sum_up);
			}

			// Right
			if (elem + adjecent_elements <= length_of_rows - 1) {
				for (int i = 0; i <= adjecent_elements - 1; ++i) {
					sum_right *= matrix.at(row).at(elem + i);
				}
				result.push_back(sum_right);

				// Diagonal Up Right
				if (row - adjecent_elements >= 0) {
					for (int i = 0; i <= adjecent_elements - 1; ++i) {
						up_right_diagonal *= matrix.at(row - i).at(elem + i);
					}
					result.push_back(up_right_diagonal);
				}
			}

			// Down
			if (row + adjecent_elements <= length_of_rows - 1) {
				for (int i = 0; i <= adjecent_elements - 1; ++i) {
					sum_down *= matrix.at(row + i).at(elem);
				}
				result.push_back(sum_down);

				// Diagonal Down Left
				if (elem - adjecent_elements >= 0) {
					for (int i = 0; i <= adjecent_elements - 1; ++i) {
						down_left_diagonal *= matrix.at(row + i).at(elem - i);
					}
					result.push_back(down_left_diagonal);
				}

				// Diagonal Down Right
				if (elem + adjecent_elements <= length_of_rows - 1) {
					for (int i = 0; i <= adjecent_elements - 1; ++i) {
						down_right_diagonal *= matrix.at(row + i).at(elem + i);
					}
					result.push_back(down_right_diagonal);
				}
			}

			unsigned long long int biggest_product = 1;

			if (result.size() > 0) {
				// Finding the biggest ones
				sort(result.begin(), result.end());
				biggest_product = result.at(result.size() - 1);
			}

			return biggest_product;
		}

		catch (...) {
			cout << row << endl;
			cout << elem << endl;
			system("pause");
		}
	}
};

class P10 {
	/*
	Problem 10 - Summation of Primes

	Problem Description:

	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
	Find the sum of all the primes below two million.

	Possible Improvements:
	
	Sieve of Eratosthenes
	https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

	*/
public:
	const long int p10_MAX = 2000000;
	P10() {
		sieve_of_eratosthenes();
	}

	void brute_force() {
		long long int result = 0;
		int i = 2;
		while (i < p10_MAX) {
			int j = 2;
			while (j <= i) {
				if (i % j == 0 && i != j) { break; }
				if (j == i) { result += i; }
				++j;
			}
			i == 2 ? ++i : i += 2;
		}
		cout << result << endl;
	}

	void sieve_of_eratosthenes() {
		int max = 2000000;
		unsigned long long int solution = 0;

		// Create an array that can hold 2000000 items
		int* array = new int[max];

		array[0] = array[1] = 0;
		
		// Fill in every index of the array with true
		for (int i = 2; i<max; i++)
			array[i] = 1;
		
		// Take the square of every number and set it to 0 
		for (int i = 2; i <= sqrt(max); i++) {
			if (array[i] == 1) {
				for (int j = i*i; j<max; j += i)
					array[j] = 0;
			}
		}

		// The indexes that contain 1 are primes
		for (int i = 0; i<max; i++) {
			if (array[i] == 1)
				solution += i;
		}
		cout << solution << endl;
		delete array;
	}

};

class P09 {
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
	P09() {
		int c = 1000;
		// Rounded
		int max_c = 1000 - 1;

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
		cout << "Finished" << endl;
	}
};

class P08 {
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

	P08() {
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

class P07 {
	/*
	Problem 7 - 10001st prime

	Problem Description:
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
	What is the 10 001st prime number?

	Possible Improvements:
	Increment j by two because even numbers cant be primes.
	*/
public:
	P07(){

		int last_prime;
		int treshold = 10001;
		int primes_found = 0;

		int i = 2;
		while (primes_found != treshold) {
			int j = 2;
			while (j <= i) {
				if (i%j == 0 && i != j) {
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
	}
};

class P06 {
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
	P06() {
		float sum_of_squares = get_sum_of_squares(100);
		float square_of_sum = get_square_of_sum(100);
		int result = square_of_sum - sum_of_squares;
		cout << "sum of squares " << sum_of_squares << endl;
		cout << "square of sum " << square_of_sum << endl;
		cout << "result " << result << endl;
	}

	float P06::get_sum_of_squares(int num) {
		float val = 0;
		for (num; num != 0; num--) {
			val += pow(num, 2);
		}
		return val;
	}

	float P06::get_square_of_sum(int num) {
		float val = 0;
		for (int i = 1; i <= num; i++) {
			val += i;
		}
		val = pow(val, 2);
		return val;
	}

};

class P05 {
	/*
	Problem 5 -

	Problem Description:


	Possible Improvements:

	*/
public:
	P05() {

	}
};

class P04 {
	/*
	Problem 4 -

	Problem Description:


	Possible Improvements:

	*/
public:
	P04() {

	}
};

class P03 {
	/*
	Problem 3 - Largest Prime Factor

	Problem Description:
	
	The prime factors of 13195 are 5, 7, 13 and 29.
	What is the largest prime factor of the number 600851475143 ?

	Possible Improvements:

	*/
public:
	P03() {
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

class P02 {
	/*
	Problem 2 -

	Problem Description:


	Possible Improvements:

	*/
public:
	P02() {

	}
};

class P01 {
	/*
	Problem 1 -

	Problem Description:


	Possible Improvements:

	*/
public:
	P01() {

	}
};