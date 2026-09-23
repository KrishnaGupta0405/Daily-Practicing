class Solution {
public:
    string reverseStr(string s, int k) {

        //  int step = 2 * k;

        // for(int i = 0; i < s.length(); i += 2*k){

        //     int start = i;
        //     int end = min(i + k - 1, (int)s.length() - 1);

        //     while(start < end){
        //         swap(s[start], s[end]);
        //         start++;
        //         end--;
        //     }
        // }

        // return s;

        bool reversed = false;
        for( int i = 0; i <=s.size()-1; i+=k){
            cout<<reversed<<endl;
            if(reversed){
                reversed = false;
                continue;
            }
            // case 1- k char available
            if(i+k<=s.length()-1){
                reverse(s.begin()+i, s.begin()+i+k);
                reversed = true;
            }
            // Case2- less than k char
            // (!s[i+k])
            else{
                reverse(s.begin()+i, s.end());
                reversed = true;
            }
            // Case3- <2k && >k
            // already takes care,
            // 2k = k + k, so first k is reversed then rest would be leaved by continue
        }    
        return s;
    }
};