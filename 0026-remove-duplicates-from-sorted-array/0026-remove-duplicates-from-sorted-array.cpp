class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Handle edge case

        int k = 1;  // Pointer for unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Found a new unique element
                nums[k] = nums[i];  // Move unique element after the last found element
                k++;
            }
        }
        return k;  // Number of unique elements
    }
};