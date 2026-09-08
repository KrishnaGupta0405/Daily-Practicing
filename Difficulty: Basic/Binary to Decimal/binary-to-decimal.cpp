class Solution {
  public:
    int binaryToDecimal(string& b) {
        // code here
        int ans =0, i=0;
        while(b!=""){
            char ld = b[b.length()-1];
            if(ld=='1') ans = pow(2,i)+ans;
            i++;
            b.pop_back();
        }
        return ans;
    }
};