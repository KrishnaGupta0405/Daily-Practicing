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
//  Aprroach -> 1
// #include<algorithm>
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>& arr){
//         if (root==NULL){
//             return;
//         }
//         inorder(root->left, arr);
//         arr.push_back(root->val);
//         inorder(root->right, arr);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         inorder(root,ans);
//         return ans[k-1];
//     }
// };

// Approach -> 2
#include<algorithm>
class Solution {
public:
int solve( TreeNode* root, int& i , int k){
    if (!root) return -1;
    int left = solve( root -> left, i, k);
    if (left != -1){
        return left;
    }
    i++;
    if ( i == k){
        return root-> val;
    }
    return solve(root->right , i, k);
}
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return solve(root, i, k);
    }
};