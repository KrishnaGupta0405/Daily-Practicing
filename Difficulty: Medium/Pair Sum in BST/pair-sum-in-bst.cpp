//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& inorderVal){
      if(!root) return;
      inorder(root->left, inorderVal);
      inorderVal.push_back(root->data);
      inorder(root->right, inorderVal);
    }
    bool findTarget(Node *root, int target) {
        //  Approach 1- Bruteforce, i.e. for evrey node, i traverse the whole tree finding its bother/sister
        // T.C.- O(N^2), S.C.-O(1)
        
        //  Approach 2- Build an inorder array & then use two pointer technique
        //  T.C.- O(N), S.C.- O(N)
        
        // Approach 3- Merge 2 pointer teachnique with inorder, i.e. traverse the array using inorder but chainging the pointer using 2 pointer technique
        //  T.C.- O(N), S.C.-O(1)
        
        // Approach 2-
        vector<int> inorderVal;
        inorder(root, inorderVal);
        int i = 0;
        int j = inorderVal.size() - 1;
        while( i < j ){
            int sum = inorderVal[i] + inorderVal[j];
            if (sum == target){
                return true;
            }
            else if ( sum > target ){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution obj;
        cout << obj.findTarget(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends