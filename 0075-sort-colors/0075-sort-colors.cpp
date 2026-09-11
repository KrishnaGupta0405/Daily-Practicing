class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();

        // initialize three pointers:
        // lo: boundary for 0s
        // mid: current element being checked
        // hi: boundary for 2s
        int lo = 0;
        int hi = n - 1;
        int mid = 0;

        // process elements until mid crosses hi
        while (mid <= hi) {
        if (arr[mid] == 0) {
            
            // current is 0: swap with lo and move both 
            // pointers forward
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // current is 1: it's already in correct position
            mid++;
        }
        else {
            // current is 2: swap with hi and move hi backward
            // do not increment mid, as swapped value needs
            // to be re-checked
            swap(arr[mid], arr[hi--]);
        }
        }

    }
};