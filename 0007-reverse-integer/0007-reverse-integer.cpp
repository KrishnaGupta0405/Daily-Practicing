class Solution {
public:
    int reverse(int n) {
        long long int x = 0;
        while (n != 0) {
            x = (x * 10) + (n % 10);
            n /= 10;
            // Check for overflow
            if (x > INT_MAX || x < INT_MIN) {
                return 0; // Return 0 in case of overflow
            }
        }
        return x;
    }
};