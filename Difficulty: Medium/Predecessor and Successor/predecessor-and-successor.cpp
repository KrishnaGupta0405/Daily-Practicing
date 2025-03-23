//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends

/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void predecessorSuccessor(Node* root, Node*& pre, Node*& suc, int key){
        Node* temp = root;
        while(temp && temp -> key != key){
            //  Current is < target
            if(temp -> key < key){
                pre = temp;  // Store potential predecessor
                temp = temp->right;
            }
            // Current in > target,
            else if(temp -> key > key){
                suc = temp;  // Store potential successor
                temp = temp -> left;
            }
        }
        
        // If the key is not found, return
        if (temp == NULL) return;

        // Find the predecessor (max in left subtree)
        if (temp->left) {
            Node* leftTree = temp->left;
            while (leftTree->right) {
                leftTree = leftTree->right;
            }
            pre = leftTree;
        }

        // Find the successor (min in right subtree)
        if (temp->right) {
            Node* rightTree = temp->right;
            while (rightTree->left) {
                rightTree = rightTree->left;
            }
            suc = rightTree;
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        //  Apprroach 1-> Make inorder array, and then
        //  Inorder Predecessor = arr[k-1]
        //  Tnorder Successor = arr[k+1]
        
        //  Approach 2-> While doing inorder traversal find the node and process its predecessor and successor
        if (!root) return;
        predecessorSuccessor(root, pre, suc, key);
    }
};


//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends