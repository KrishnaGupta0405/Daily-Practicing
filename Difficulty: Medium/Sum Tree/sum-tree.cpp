//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool, int> isSumFast(Node* root) {
        if (root == NULL) {
            // An empty tree is a Sum Tree with sum 0
            return {true, 0};
        }

        // Check for leaf nodes
        if (root->left == NULL && root->right == NULL) {
            // A leaf node is a Sum Tree, with its value as the sum
            return {true, root->data};
        }

        // Recursive calls for left and right subtrees
        pair<bool, int> leftT = isSumFast(root->left);
        pair<bool, int> rightT = isSumFast(root->right);

        // Check if left and right subtrees are Sum Trees
        bool left = leftT.first;
        bool right = rightT.first;

        // Check the Sum Tree condition for the current node
        bool condn = (root->data == leftT.second + rightT.second);

        pair<bool, int> ans;
        if (left && right && condn) {
            ans.first = true;
            // Update the sum for the current subtree
            ans.second = root->data + leftT.second + rightT.second;
        } else {
            ans.first = false;
        }

        return ans;
    }

    bool isSumTree(Node* root) {
        return isSumFast(root).first;
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;

        getline(cin, s);

        Node* root = buildTree(s);
        Solution ob;
        if (ob.isSumTree(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 1;
}
// } Driver Code Ends