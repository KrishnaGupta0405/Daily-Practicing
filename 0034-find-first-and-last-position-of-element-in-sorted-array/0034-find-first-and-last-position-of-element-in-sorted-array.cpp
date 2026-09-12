class Solution {
public:

    int FirstOcc(vector<int>& arr, int size, int target){
        int s = 0, e = arr.size()-1;
        int mid = s + (e - s)/2;
        int ans = -1; 

        while(s <= e){
            if(arr[mid] == target ){
                ans = mid;
                e = mid -1; 
            }
            else if(arr[mid] > target){
                e = mid-1;
            }
            else{
                s = mid +1;
            }
            mid = s + (e - s)/2;
        }
        return ans;
    }

    int LastOcc(vector<int>& arr, int size, int target){
        int s = 0, e = arr.size()-1;
        int mid = s + (e - s)/2;
        int ans = -1; 

        while(s <= e){
            if(arr[mid] == target ){
                ans = mid;
                s = mid + 1; 
            }
            else if(arr[mid] > target){
                e = mid-1;
            }
            else{
                s = mid +1;
            }
            mid = s + (e - s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans(2, -1);
        if(arr.size() == 0) return ans;
        int F =  FirstOcc(arr, arr.size(), target);
        int L =  LastOcc(arr, arr.size(), target);
        ans = {F ,L};
        return ans;
    }
};