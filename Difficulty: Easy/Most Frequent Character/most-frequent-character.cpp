class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        vector<int> arr(26,0);
        for (char c : s) {
            c = tolower(c);
            arr[c - 'a']++;
        }
        // for(auto i : s){
        //     arr[i-'a']++;
        // }
        int ans = 0;
        for(int i = 0; i <= arr.size()-1; i++){
            if(arr[i] > arr[ans]){
                ans = i;
            }
            else if(arr[i] == arr[ans]){
                ans = min(i,ans);
            }
        }
        return 'a'+ans;
    }
    
};