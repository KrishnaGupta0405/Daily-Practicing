//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
    // Base case: If the stack is empty, push the element and return the stack
    if (st.empty()) {
        st.push(x);
        return st;
    }

    // Pop the top element from the stack
    int top = st.top();
    st.pop();

    // Recursively call insertAtBottom for the remaining stack
    st = insertAtBottom(st, x);

    // Push the previously popped element back onto the stack
    st.push(top);

    // Return the modified stack
    return st;
}
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends