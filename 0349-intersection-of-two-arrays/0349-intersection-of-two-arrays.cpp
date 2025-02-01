class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end()); // Store elements of nums1
        unordered_set<int> result; // To store intersection elements

        for (int num : nums2) {
            if (set.find(num) != set.end()) {  // if the element is not found then the set.end() is returned
                result.insert(num); // If present in nums1, add to result
            }
        }

        return vector<int>(result.begin(), result.end()); // Convert set to vector
    }
};