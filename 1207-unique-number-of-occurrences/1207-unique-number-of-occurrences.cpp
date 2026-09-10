class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // vector<int> count;
        // for(int i=0;i<arr.size();i++){
        //     count[arr[i]]++;
        // }
        // sort(count.begin(), count.end());
        // for(int i=0; i<count.size();i++){
        //     if(i+1<count.size() && count[i]==count[i+1]) return false;
        // }
        // return true;

        // Above solution not feasible, as count total size not intialized, and array may contain negative values also

        // Using Unorderd_map, unordered_Set

        unordered_map<int, int> freq;
        for(auto x : arr){
            freq[x]++;
        }
        unordered_set<int> s;
        for(auto x:freq){
            s.insert(x.second);
        }
        return freq.size() == s.size();
    }
};