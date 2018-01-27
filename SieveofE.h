/*============================================================================
 * SieveofE.h
 *
 * Author: Angel Morales
 * ============================================================================
 */


#ifndef SIEVEOFE_H_
#define SIEVEOFE_H_

class PrimesSieve {
public:
	PrimesSieve(int limit);
	void display_primes() const;
	int num_primes() const {return num_primes_;}
	int count_num_primes() const;
	int get_max_primes() const;
	int num_digits(int num) const;
	void sieve();
	~PrimesSieve();
private:
	bool * const is_prime_;
	const int limit_;
	int num_primes_;
};


#endif /* SIEVEOFE_H_ */
