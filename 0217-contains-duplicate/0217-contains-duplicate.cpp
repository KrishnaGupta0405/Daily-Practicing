class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> myMap;
    bool answer = false;

    for (int i = 0; i < nums.size(); i++) {
        //i.e. the elemenet is already present in the array
        if (myMap.find(nums[i]) != myMap.end()) { 
            answer = true;
            break;
        } else {
            myMap[nums[i]] = 1;
        }
    }

    return answer;
    }
};