#include <queue>
#include <vector>
using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> Outer;
        if (!root) return Outer;  // Handle empty tree case

        queue<TreeNode*> q;
        q.push(root);
        bool LeftToRight = true;

        while (!q.empty()) {
            // Not like the love babbar told, to insert the NULL pointer at the end of the queue, to track the end of the level, i am soley relying at the size of the queue, to declare it as the level, & process all the elements at that level,
            // & then move to the next level, by getting its, q.size()...
            
            int size = q.size();  // Number of nodes at current level
            vector<int> Inner(size);  // Create a vector for the current level

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Insert according to the zigzag order
                int index = LeftToRight ? i : (size - 1 - i);
                Inner[index] = temp->val;

                // Push child nodes for the next level
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            // After finishing one level, add the current level to Outer
            Outer.push_back(Inner);

            // Toggle the zigzag order for the next level
            LeftToRight = !LeftToRight;
        }

        return Outer;
    }
};
