class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // Sort the strings directly
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t; // Compare sorted strings

    }
};