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
#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> Outer;
        vector<int> Inner;

        if( root == NULL ){
            return Outer;
        }
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL ){
                //One level is completed
                Outer.push_back(Inner);
                Inner.clear();

                //Intializing the next level
                if (!q.empty()){
                    q.push(NULL);
                }
            }
            else{ 
                //input the element in the same array i.e. the same level
                Inner.push_back(temp->val);
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
            }
        }
        return Outer;
    }
};