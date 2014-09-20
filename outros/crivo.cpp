/*
 * Exemplo do algoritmo crivo, para encontrar e armazenar 
 * os números primos entre 2 e lim, inclusive.
 */

#include <string.h>
#include <stdio.h>
#include <math.h>
typedef unsigned long long int lli;

bool isprime[3000001];
lli prime[2000010], prime_cont = 0;
lli lim = 3000000;

int main() {
  prime[prime_cont++] = 2;

	memset(isprime, true, sizeof(isprime));
	for(lli i=3; i<=lim; i+=2) if(isprime[i]) {
		prime[prime_cont++] = i;
		
		for(lli j=i*i; j<=lim; j+=i) {
			isprime[j] = false;
		}
	}
	//~ printf("done with %llu primes.\n", prime_cont);
	//~ return 0;
}
