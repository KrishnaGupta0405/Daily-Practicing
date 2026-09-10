class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j =0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int maxi= max(nums1[nums1.size()-1],nums2[nums2.size()-1]);
        vector<bool> ans(maxi+1);

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                ans[nums1[i]]=true;
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        
        vector<int> arr;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i]==true){
                arr.push_back(i);
            }
        }
        return arr;
    }
};