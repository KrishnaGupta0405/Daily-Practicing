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
 //Balanced height is such that the diffrence between the height of left subtree and right subtree is +-1
class Solution {
public:
    pair<bool,int> balancedFast(TreeNode* root){  
        //first -balanced or not, second-> height diffrence between L&R subtree
        if (root == NULL ){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<bool,int> leftT = balancedFast(root->left);
        pair<bool,int> rightT = balancedFast(root->right);

        bool left = leftT.first;
        bool right = rightT.first;
        bool diff = abs(leftT.second - rightT.second)<=1;

        pair<bool,int> ans;
        ans.second = max(leftT.second ,rightT.second)+1;
        // Is the left and right subtree balanced? and their height diff is <=1?
        if (left && right && diff){
            ans.first = true; //yes tree is balance till here
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return balancedFast(root).first;
    }
};