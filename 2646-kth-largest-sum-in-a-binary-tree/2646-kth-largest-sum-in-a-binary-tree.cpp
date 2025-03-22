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
#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // Edge case: Empty tree
        
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<long long> levelSums;
        
        // BFS traversal to compute level sums
        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            levelSums.push_back(levelSum);
        }
        
        // Sort level sums in descending order
        std::sort(levelSums.rbegin(), levelSums.rend());
        
        // Check if k is valid
        if (k > levelSums.size()) return -1;
        
        return levelSums[k - 1]; // Return k-th largest level sum
    }
};
