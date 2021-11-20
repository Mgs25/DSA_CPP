#include <bits/stdc++.h>
using namespace std;

/* Problem statement: 
 * Given a number n, print all prime numbers smaller than or equal to n.
 * Input:
 *    A single line contains an integer n
 * Output:
 *    A single line output printing all the prime numbers less than or equal to n, separated by a whitespace.
 *
 * Approach: Sieve of eratosthenes
 * Time complexity: O(N log (log N))
*/

void Sieve(int n) {
    vector<bool> prime (n + 1); // Create a vector of n + 1 elements
    fill(prime.begin(), prime.end(), true); // Fill vector with true

    for (int p { 2 }; p * p <= n; p++) {
        if (prime.at(p)) { // if prime[p] is true, then multiples of prime[p] are not primes
            for (int i { p * p }; i <= n; i += p) // set all multiples of prime[p] to false
                prime.at(i) = false;
        }
    }

    for (int p { 2 }; p <= n; p++) { // Print all the primes <= n
        if (prime.at(p)) cout << p << " "; // if prime[p] is true, then it is a prime
    }
}

int main() {
    const int n { 15 }; // n - input
    Sieve(n);
}