class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case for INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Return INT_MAX to prevent overflow
        }

        // Handle edge case where divisor is 1 or -1
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

        // Determine if the result is negative
        bool isNegative = (dividend < 0) ^ (divisor < 0); 

        // Convert dividend and divisor to long long to handle overflow cases
        long long absDividend = labs((long long)dividend);
        long long absDivisor = labs((long long)divisor);

        int count = 0;
        
        // Perform division using repeated subtraction
        while (absDividend >= absDivisor) {
            absDividend -= absDivisor;
            count++;
        }

        // Return the result with the correct sign
        return isNegative ? -count : count;
    }
};
