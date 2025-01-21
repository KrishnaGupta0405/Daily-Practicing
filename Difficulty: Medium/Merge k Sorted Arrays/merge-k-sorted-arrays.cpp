//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int r, int c){
        data = d;
        row = r;
        col =c;
    }
};
class compare{
    public:
    bool operator()(node* a, node*b){
        return (a->data > b->data);
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node*,vector<node*>,compare> minH;
        for ( int i = 0; i<K; i++){
            node* temp = new node(arr[i][0], i, 0);  //data,row,col
            minH.push(temp);
        }
        vector<int> ans;
        while(minH.size()>0){
            node* temp = minH.top();
            minH.pop();
            ans.push_back(temp->data);
            
            int row = temp->row; // ->
            int col = temp->col; // ↓
            
            if( col + 1 < arr[row].size()){
                node* temp2 = new node(arr[row][col+1], row, col+1);
                minH.push(temp2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends