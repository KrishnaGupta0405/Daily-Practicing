// void reverse(vector<char>& s, int n, int i){
//     if (i==n){
//         return;
//     }
//     reverse(s,n,i-1);
//     return s.push_back(i);

// }
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            int temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }
    }
};