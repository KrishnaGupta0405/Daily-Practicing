class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string temp = "";
        for(auto i : s) if(i != ' ') temp.push_back(i);
        return temp;
    }
};