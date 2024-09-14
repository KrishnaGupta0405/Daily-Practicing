#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet;
        
        // Insert all positive numbers into the set using a simple for loop
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                numSet.insert(nums[i]);
            }
        }
        
        // Check the smallest missing positive number starting from 1
        int count = 1;
        while (numSet.find(count) != numSet.end()) {
            count++;
        }
        
        return count;
    }
};
