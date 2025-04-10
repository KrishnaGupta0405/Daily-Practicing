class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]); 
            } 
            else {
                if (!st.empty() && (
                        (st.top() == '(' && s[i] == ')') ||
                        (st.top() == '{' && s[i] == '}') ||
                        (st.top() == '[' && s[i] == ']'))
                    ){
                    st.pop(); 
                }
                else {
                    return false; 
                }
            }
        }
        // If stack is empty, return true (balanced), otherwise false
        return st.empty();
    }
};