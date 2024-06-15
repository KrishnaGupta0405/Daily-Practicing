#include <iostream>
#include <string>
#include <climits> // for INT_MAX and INT_MIN

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int sign = 1;
        int result = 0;
        
        // Step 1: Ignore leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Handle signs
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Read digits and convert to integer
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Step 4: Check for overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // Apply sign to result
        return result * sign;
    }
};