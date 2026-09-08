class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool ans = false;
        while(n!=0){
            int digit = n & 1;
            if (digit == true){
                if(ans== true){
                    return false;
                }
                else{
                    ans = true;
                }
            }
            n>>=1;
        }
        return ans;
    }
};