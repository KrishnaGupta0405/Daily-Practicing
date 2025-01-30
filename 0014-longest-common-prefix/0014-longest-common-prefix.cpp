class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Sort the vector of strings
    sort(strs.begin(), strs.end());

    // Compare the first and last strings
    // in the sorted list
    string first = strs.front();
    string last = strs.back();
    int minLength = min(first.size(), last.size());

    int i = 0;
  
    // Find the common prefix between the first
    // and last strings
    while (i < minLength && first[i] == last[i]) {
        i++;
    }

    // Return the common prefix
    return first.substr(0, i);
    }
};