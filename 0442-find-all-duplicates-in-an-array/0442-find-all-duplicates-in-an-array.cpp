class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto num : nums) freq[num]++;

        vector<int> duplicates;
        for(auto num : freq) if(num.second > 1) duplicates.push_back(num.first);

        return duplicates;
    }
};