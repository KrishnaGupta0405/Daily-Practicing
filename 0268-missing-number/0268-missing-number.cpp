class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> dummy(nums.size()+1, false);
        for(int i=0; i<nums.size(); i++){
            dummy[nums[i]] = true;
        }
        int ans = 0;
        for( int i=0; i< dummy.size(); i++){
            if(dummy[i]!=true){
                ans = i;
                break;
            }
        }
        return ans;
    }
};