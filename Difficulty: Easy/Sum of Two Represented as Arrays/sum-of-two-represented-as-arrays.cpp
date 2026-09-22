class Solution {
  public:
    vector<int> addArrays(vector<int>& arr1, vector<int>& arr2) {
        // code here
        int m = arr1.size()-1;
        int n = arr2.size()-1;
        int carry = 0;
        vector<int> ans;
        
        while(m >= 0 && n >= 0){
            int temp = carry + arr1[m] + arr2[n];
            if(temp > 9){
                carry = 1;
                temp %= 10;
            }
            else{
                carry = 0;
            }
            ans.insert(ans.begin(), temp);
            m--;
            n--;
        }
        
        // Either arr1 or arr2 will be left
        while( m >= 0){
            int temp = carry + arr1[m];
            if(temp > 9){
                carry = 1;
                temp %= 10;
            }
            else{
                carry = 0;
            }
            ans.insert(ans.begin(), temp);
            m--;
        }
        
        while( n >= 0){
            int temp = carry + arr2[n];
            if(temp > 9){
                carry = 1;
                temp %= 10;
            }
            else{
                carry = 0;
            }
            ans.insert(ans.begin(), temp);
            n--;
        }
        
        // Edge case: carry is still left
        if(carry != 0){
            ans.insert(ans.begin(), carry);
        }
        return ans;
        
    }
};