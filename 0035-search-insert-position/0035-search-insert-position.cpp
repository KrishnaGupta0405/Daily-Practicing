class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoids overflow
        
        if (nums[mid] == tar) 
            return mid;
        else if (nums[mid] < tar) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    
    return left; // Handles both "less than smallest" and "greater than largest" cases
    }
};