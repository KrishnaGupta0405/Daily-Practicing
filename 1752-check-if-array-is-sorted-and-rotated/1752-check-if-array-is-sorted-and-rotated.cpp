class Solution {
public:
    bool check(vector<int>& nums) {
        // checking how many time array breaked the ascending order rule
        // if <=1 then true otherwise false
        int n = nums.size();
        int count = 0;
        
        for (int i = 1; i < n; i++){
            if (nums[i - 1] > nums[i]){
                count++;}
        }
        // Check if the last element is greater than the first element
        if (nums[n - 1] > nums[0]){
            count++;
        }
        return count <= 1;   
        
    }
};