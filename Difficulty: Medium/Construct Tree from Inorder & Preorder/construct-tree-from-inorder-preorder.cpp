//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    //Mapping of inorder element to its index
    void createMapping( vector<int> inorder, int n, map<int,int>& nodeToIndex  ){
        for ( int i = 0 ; i < n ; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node* solve( vector<int> inorder, vector<int> preorder, int& Index, int n, int inorderStart, int inorderEnd, map<int,int>& nodeToIndex){
        if( Index > n || inorderStart > inorderEnd ){
            return NULL;
        }
        
        int element = preorder[Index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->left = solve(inorder, preorder, Index, n, inorderStart, position-1, nodeToIndex );
        root->right = solve(inorder, preorder, Index, n, position+1, inorderEnd, nodeToIndex );
        
        return root;
    }
    
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // if(inorder.size() != preorder.size()){
        //     return NULL;
        // }
        int preorderIndex = 0;
        int n = inorder.size();  // preorder.size()
        
        map<int,int> nodeToIndex;
        createMapping(inorder , n , nodeToIndex);
        
        Node* ans = solve(inorder, preorder, preorderIndex, n, 0 , n-1, nodeToIndex);
        return ans;
    }
};


















//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends