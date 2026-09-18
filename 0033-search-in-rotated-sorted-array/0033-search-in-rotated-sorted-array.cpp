class Solution {
public:
    int findPivot(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(arr[mid] >= arr[0]) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }

        return s;
    }

    int binarySearch(vector<int>& arr, int s, int e, int target) {
        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(arr[mid] == target)
                return mid;

            if(arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivot(nums);

        if(target >= nums[pivotIndex] && target <= nums.back()) {
            return binarySearch(nums, pivotIndex, nums.size() - 1, target);
        }

        return binarySearch(nums, 0, pivotIndex - 1, target);
    }
};