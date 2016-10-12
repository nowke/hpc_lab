#include <iostream>
#include <math.h>
#include <string.h>
#include <omp.h>

using namespace std;

double t;

/**
* Marks all multiples of `multiple` from `low*2` till `high`
*
* eg: If low=4, high=15, multiple=2 => marks 4, 6, 8, 10, 12, 14 as `false`
*/
long mark_multiples(bool prime[], long low, long multiple, long high) {
    long i;
    for (i=low; i <= high; i += multiple)
    prime[i] = false;
    return i;
}

/**
* Sieve of Eratosthenes(n) - All Prime numbers smaller or equal to n
*
*/
void SieveOfEratosthenes(long N) {
    // Create `bool` array 'prime[0..n]', Initialize all elements to `true`
    bool* prime = new bool[N+1];
    for (long p=2; p<=N; p++)
    prime[p] = true;

    double t1 = omp_get_wtime();
    for (long p=2; p*p <= N; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        mark_multiples(prime, p*2, p, N); // Update all multiples of p
    }

    double t2 = omp_get_wtime();
    t = (t2-t1)*1000;
}

/**
* Sieve of Eratosthenes with Segmentation
*
*/
void CacheSieve(long N) {
    // Create `bool` array 'prime[0..n]', Initialize all elements to `true`
    bool* prime = new bool[N+1];
    for (long p=2; p<=N; p++)
    prime[p] = true;

    long M = (long) sqrt((double) N);
    long* factor  = new long[M];
    long* striker = new long[M];
    long n_factor = 0;

    double t1 = omp_get_wtime();

    // Compute all primes smaller than or equal
    // to square root of `N` using simple sieve
    for (long p=2; p <= M; p++)
    if (prime[p] == true) {
        striker[n_factor] = mark_multiples(prime, p*2, p, M);
        factor[n_factor++] = p;
    }

    // Chop Sieve to Windows of Size `sqrt(n)`
    for (long window = M+1; window <= N; window += M) {
        long limit = min(window + M - 1, N); // Max value of window (and not exceed N)

        // Walk through the current window
        for (long i=0; i < n_factor; i++)
        striker[i] = mark_multiples(prime, striker[i], factor[i], limit);
    }

    double t2 = omp_get_wtime();
    t = (t2 - t1)*1000;
}

int main(int argc, char* argv[]) {
    long N = atol(argv[1]);
    SieveOfEratosthenes(N);
    cout << "Cache Unfriendly Sieve -> Time: " << t << "ms" << endl;
    CacheSieve(N);
    cout << "Cache Friendly Sieve -> Time: " << t << "ms" << endl;
}
