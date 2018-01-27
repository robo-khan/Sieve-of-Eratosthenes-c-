//============================================================================
// Name        : SieveofE.cpp
// Author      : Angel Morales
// Description : Sieve of Eratosthenes algorithm in C++
//============================================================================

#include "SieveofE.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
	cout << "**************************** " << "Sieve of Eratosthenes"
			<< " ****************************" << endl;

	int stop = 0;
	//initialize loop to continue program as long as user allows.
	do	{
		cout << "Search for primes up to: ";
		string limit_str;
		cin >> limit_str;
		int limit;

		// Use stringstream for conversion.
		istringstream iss(limit_str);

		// Check for error.
		if (!(iss >> limit)) {
			cerr << "Error: Input is not an integer." << endl;
			return 1;
		}
		if (limit < 2) {
			cerr << "Error: Input must be an integer >= 2." << endl;
			return 1;
		}

		PrimesSieve ps(limit);
		ps.display_primes();

		cout<<"\n\nTO CONTINUE ENTER '0', TO END PROGRAM ENTER '1'"<<endl;
		cin>>stop;
	} while(stop != 1);
}




