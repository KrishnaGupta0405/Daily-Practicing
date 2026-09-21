class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k %n; //Normalisizing the rotation value
        // if array size if 5, then both 7 and 2 rotation performed seperately would give the same answer
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }
};