class Solution {
  public:
    int lengthString(string &s) {
        // code here
        int count = 0 ;
        for(auto in : s) count ++;
        return count;
    }
};