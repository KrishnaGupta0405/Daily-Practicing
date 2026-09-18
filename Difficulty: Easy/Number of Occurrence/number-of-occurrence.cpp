class Solution {
  public:
    
    int firstOcc(vector<int>& arr, int target){
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                e = mid -1;
            }
            else if (arr[mid]>target){
                e = mid -1;
            }
            else{
                s = mid +1;
            }
            mid = s + (e-s)/2;
        }
    }
    
    int lastOcc(vector<int>& arr, int target){
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid]==target){
                ans = mid;
                s = mid +1 ;
            }
            else if (arr[mid]>target){
                e = mid -1;
            }
            else{
                s = mid +1;
            }
            mid = s + (e-s)/2;
        }
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int startIndex = firstOcc(arr, target);
        int lastIndex = lastOcc(arr, target);
        int count = lastIndex - startIndex;
        return count;
    }
};
