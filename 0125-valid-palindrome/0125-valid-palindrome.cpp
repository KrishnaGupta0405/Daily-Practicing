class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";
        for (char c : s) {
            if (isalnum(c)) {
                word += tolower(c);
            }
        }
        if (word.length() <= 1) return true;
        
        for (int i = 0; i < word.length() / 2; i++) {
            if (word[i] != word[word.length() - 1 - i]) return false;
        }
        return true;
    }
};
