//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;
    
    int signum(int a, int b){
        if(a==b){
            return 0;
        }
        else if( a>b){
            return 1;
        }
        else{
            return -1;      // a<b
        }
    }
    //Function to insert heap.
    void insertHeap(int &n)
    {
        balanceHeaps( maxHeap , minHeap , n , median );
    }
    
    //Function to balance heaps.
    void balanceHeaps(priority_queue<int> &maxi, priority_queue<int,vector<int>,greater<int>> &mini, int ele, double & median)
    {
     switch (signum(maxi.size(),mini.size())){
         
        //  Left == right
        case 0: 
        if(ele>median){
             mini.push(ele);
             median = mini.top();
         }
         else{
             maxi.push(ele);
             median = maxi.top();
         }
         break;
         
        // left > right
        case 1: 
        if( ele > median){
            mini.push(ele);
            median = (maxi.top() + mini.top()) / 2.0;
        }
        else{
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(ele);
            median = (maxi.top() + mini.top()) / 2.0;
        }
        break;
        
        // Left < right
        case -1:
        if (ele > median) {
            maxi.push(mini.top());
            mini.pop();
            mini.push(ele);
        } else {
            maxi.push(ele);
        }
        median = (maxi.top() + mini.top()) / 2.0;
        break;
    }
}
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends