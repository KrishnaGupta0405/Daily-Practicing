class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }
        
        // Numbers ending in 0 are not palindromes (except for 0 itself)
        if (x != 0 && x % 10 == 0) {
            return false;
        }
        
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // Check if the original number (first half) equals the reversed second half
        // or if we ignore the middle digit in an odd length number
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
