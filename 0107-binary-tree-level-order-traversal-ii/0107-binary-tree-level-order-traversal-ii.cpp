/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// Option 1
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> Outer;
        if (!root) return Outer;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> Inner;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                Inner.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            Outer.insert(Outer.begin(), Inner); // Add at the beginning to avoid reversing
        }
        return Outer;
    }


    // Option 2-> just lil change of levelOrderTraversal
    
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<vector<int>> Outer;
    //     vector<int> Inner;

    //     if( root == NULL ){
    //         return Outer;
    //     }
    //     q.push(root);
    //     q.push(NULL);

    //     while(!q.empty()){
    //         TreeNode* temp = q.front();
    //         q.pop();
    //         if (temp == NULL ){
    //             //One level is completed
    //             Outer.insert(Outer.begin(),Inner);
    //             Inner.clear();

    //             //Intializing the next level
    //             if (!q.empty()){
    //                 q.push(NULL);
    //             }
    //         }
    //         else{ 
    //             //input the element in the same array i.e. the same level
    //             Inner.push_back(temp->val);
    //             if (temp->left){
    //                 q.push(temp->left);
    //             }
    //             if (temp->right){
    //                 q.push(temp->right);
    //             }
    //         }
    //     }
    //     return Outer;
    // }

};
