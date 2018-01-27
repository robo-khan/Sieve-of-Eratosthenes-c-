/*============================================================================
 * SieveofE.cpp
 *
 * Author: Angel Morales
 *============================================================================
 *FUNCTIONS:
 * PrimesSieve(): Constructor
 * ~PrimesSieve(): Destructor
 * display_primes(): Method to display prime numbers. It uses the limit_ variable and displays all of the prime numbers up to the limit.
 * count_num_primes(): Method that returns the amount of prime numbers up until the limit.
 * get_max_primes(): Method that determines the maximum prime number.
 * num_digits(): Method that takes in an integer and determines the amount of digit places it has.
 * sieve(): Method used to determine which elements are prime numbers and which are not.
 *============================================================================
 */

#include "SieveofE.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

PrimesSieve::PrimesSieve(int limit) :
		is_prime_(new bool[limit + 1]), limit_(limit) {sieve();
		num_primes_ = count_num_primes();
}

void PrimesSieve::display_primes() const {
	const int max_prime_width = num_digits(get_max_primes()); //used to determine the width of the maximum prime number
	const int primes_per_row = 80 / (max_prime_width + 1);    //used to determine the maximum amount of numbers to print in a row
	int count = 0; 										    //counter used to measure how many primes are in a row at the moment

	//Beginning dialogue
	cout << '\n';
	cout << "Number of primes found: " << num_primes() << endl;
	cout << "Primes up to " << limit_ << ":" << endl;

	//a for loop that goes through the array of booleans and prints the index of all the true elements.
	//An element that is true in the array of booleans means that it is prime.
	for (int i = 2; i <= limit_; i++) {
		if (is_prime_[i]) {
			if (i == get_max_primes()) {						//Fixes the spacing on the last prime number
				cout << i; 									//prints the last prime number
				count = 0; 									//reset counter
				break; 										//get out of the loop, this was the last prime number anyways
			}
			if (!(primes_per_row >= num_primes())) { 		//if the number of primes exceed the amount allowed in a row, then change the formatting of the spacing
				cout << setw(max_prime_width);
			}
			if(count +1 < primes_per_row) {
			cout << i << " "; 								//prints the index of the prime number
			}
			count++; 										//increments counter
		}
		if (primes_per_row == count) { 						//if the counter(amount of numbers printed in a row) exceeds the amount allowed, then create a new row
			cout << i;
			cout << '\n'; 									//create a new row for the rest of the primes numbers to be displayed
			count = 0; 										//reset the counter
		}
	}
}

int PrimesSieve::count_num_primes() const {
	int x = 0;
	for (int i = 2; i <= limit_; i++) {
		if (is_prime_[i] == true) {
			x++;
		}
	}
	return x;
}

int PrimesSieve::get_max_primes() const {
	int x = 0;
	for (int i = 0; i <= limit_; i++) {
		if (is_prime_[i]) {
			x = i;
		}
	}
	return x;
}

int PrimesSieve::num_digits(int num) const {
	if (num < 10) {
		return 1;
	} else {
		return 1 + num_digits(num / 10);
	}
}

//prime numbers = true. non-prime numbers = false
void PrimesSieve::sieve() {
	for (int i = 2; i <= limit_; i++) { 						//for loop used to initialize the array of booleans to all true.
		is_prime_[i] = true;
	}
	for (int i = 2; i <= sqrt(limit_); i++) { 				//for loop used to mark off all non-prime numbers as false
		if (is_prime_[i]) {
			for (int j = i * 2; j <= limit_; j += i) {
				is_prime_[j] = false;
			}
		}
	}
}

PrimesSieve::~PrimesSieve() {
	delete[] is_prime_;
}
