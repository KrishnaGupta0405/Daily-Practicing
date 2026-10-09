class Solution {
  public:
  
    void solve( string str, string output, int index, vector<string>& ans){
        //base case
        if(index >= str.length()){
            // if(output.length() > 0){
                ans.push_back(output);
            // }
            return;
        }

        // exclude
        solve(str, output, index + 1, ans);

        //include
        char ele = str[index];
        output.push_back(ele);
        solve(str, output, index +1, ans);
    }
        
    vector<string> powerSet(string &str) {
        vector<string> ans;
        string output = "";
        int index = 0;
        solve(str,output, index, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};