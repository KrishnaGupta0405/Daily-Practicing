class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow cases
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0); // XOR to check if signs are opposite

        // Convert both dividend and divisor to positive values using long long
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long result = 0;

        // Left shift divisor until it exceeds the dividend
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            result += multiple;
        }

        // Apply the sign to the result
        result = isNegative ? -result : result;

        // Handle overflow
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return result;
    }
};
