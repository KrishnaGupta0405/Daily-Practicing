bool getBit(long long n, int pos) {
    return ((n & (1LL << pos)) != 0); // use 1LL to indicate long long
}

long long setBit(long long n, int pos) {
    return (n | (1LL << pos)); // use 1LL to indicate long long
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long result = 0; // use long long for result
        for (int i = 0; i < 64; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (getBit(nums[j], i)) {
                    sum++;
                }
            }
            if (sum % 3 != 0) {
                result = setBit(result, i);
            }
        }
        return static_cast<int>(result); // cast result back to int
    }
    // Basically we are taking size of result in 64 bits,
    // Now iterating through loop of i till 64 (for position purpose), then
    // iterating loop of j to get element of arr now if element of arr has 1 at
    // i'th position, then incrementing sum++ Atlast, checking if sum%3!=0
    // {gives result} then setting 1 at the result's place in variable result,
    // which will ultimately give the answer... :) Please note that i'th loop
    // should run for 64, but i am getting error that 32bit left shift is too
    // big, hence iterating the loop till 31, if you find solution please
    // comment...
};