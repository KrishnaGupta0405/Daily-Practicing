/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int c;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if ( root == NULL ){
            return ans;
        }
        //   HD,     LVl, Node->data
        map<int, map<int, vector<int>>> nodes;  
        //          Root,          HD, Lvl
        queue<pair<TreeNode*, pair<int,int>>> q; 

        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair< TreeNode*, pair< int,int>> temp = q.front(); q.pop();            

            TreeNode* FrontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].push_back(FrontNode->val);
            if (FrontNode-> left){
                q.push(make_pair(FrontNode->left, make_pair(hd-1, level +1)));
            }
            if (FrontNode-> right){
                q.push(make_pair(FrontNode->right, make_pair(hd+1, level +1)));
            }
        }
        // queue->  root->data, horizontal Distance, Level
        //  map-> Horizontal Distance, Level, Node->data
        // [level, hd]
        for (auto i : nodes) { // Loop over horizontal distances
    vector<int> temp;
    for (auto j : i.second) { // Loop over levels
        sort(j.second.begin(), j.second.end()); // Sort values at the same level
        for (auto k : j.second) { // Loop over the sorted node values
            temp.push_back(k);
        }
    }
    ans.push_back(temp);
}

        return ans;
    }
};