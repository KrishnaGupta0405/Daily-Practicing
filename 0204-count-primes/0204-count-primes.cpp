class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Only consider odd numbers.
        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // 2 is the only even prime.
        int count = 1;

        for (int i = 3; i * i < n; i += 2) {

            if (isPrime[i]) {

                // Start from i*i.
                // Only visit odd multiples.
                for (int j = i * i; j < n; j += 2 * i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        // Count remaining odd primes
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};