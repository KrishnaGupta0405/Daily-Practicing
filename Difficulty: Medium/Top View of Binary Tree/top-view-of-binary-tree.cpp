//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
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
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
        void bottom(Node* root, vector<int>& ans) {
        // Map to store horizontal distance (hd) and corresponding bottom-most node value
        map<int, int> bottomNode; 
        // Queue to perform BFS: stores pairs of (node, horizontal distance)
        queue<pair<Node*, int>> q;
        
        if (!root) return; // Handle edge case: Empty tree
        
        q.push(make_pair(root, 0)); // Start BFS with root node at hd = 0
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
    
            Node* frontNode = temp.first;
            int hd = temp.second;
    
            // Update the map for the bottom view (always overwrite for the same hd)
            if(bottomNode.find(hd)==bottomNode.end()){
                bottomNode[hd] = frontNode->data;
            }
            // Push the left child with hd-1
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            // Push the right child with hd+1
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
    
        // Extract the values from the map in sorted order of hd
        for (auto i : bottomNode) {
            ans.push_back(i.second);
        }
    }

    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == NULL ){
            return ans;
        }
        bottom(root,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node* root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends