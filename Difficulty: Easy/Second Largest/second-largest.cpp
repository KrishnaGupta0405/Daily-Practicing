//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
    if (arr.size() < 2) return -1; // If less than 2 elements, return -1

    int first = INT_MIN, second = INT_MIN;

    for (int num : arr) {
        if (num > first) {  // Found new largest
            second = first;
            first = num;
        } else if (num > second && num < first) {  // Found second largest
            second = num;
        }
    }

    return (second == INT_MIN) ? -1 : second; // Return -1 if no second largest exists
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends