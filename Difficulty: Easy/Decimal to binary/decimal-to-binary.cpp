#include <string>
#include <math.h>
class Solution {
  public:
    string decToBinary(int n) {
        // code here
        int i =0;
        string ans = "";
        while (n != 0){
            int ld = n % 2;
            if(ld==0){
                ans+='0';
            }
            else{
                ans+='1';
            }
            i++;
            n/=2;
        }
        string anss="";
        for(int i=ans.length()-1;i>=0;i--){
            anss+=ans[i];
        }
        return anss;
    }
};