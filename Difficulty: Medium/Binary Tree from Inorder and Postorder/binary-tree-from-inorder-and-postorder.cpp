//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    //Mapping of inorder element to its index
    void createMapping( vector<int> inorder, int n, map<int,int>& nodeToIndex  ){
        for ( int i = 0 ; i < n ; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node* solve( vector<int> inorder, vector<int> postorder, int& Index, int n, int inorderStart, int inorderEnd, map<int,int>& nodeToIndex){
        if( Index < 0 || inorderStart > inorderEnd ){
            return NULL;
        }
        
        int element = postorder[Index--];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->right = solve(inorder, postorder, Index, n, position+1, inorderEnd, nodeToIndex );
        root->left = solve(inorder, postorder, Index, n, inorderStart, position-1, nodeToIndex );
        
        return root;
    }
    
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        
        int n = inorder.size();  // or postorder.size()
        int postorderIndex = n-1;
        
        map<int,int> nodeToIndex;
        createMapping(inorder , n , nodeToIndex);
        
        Node* ans = solve(inorder, postorder, postorderIndex, n, 0 , n-1, nodeToIndex);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends