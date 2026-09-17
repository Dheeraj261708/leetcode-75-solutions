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
private:
    int maxPath = 0;
    void dfs(TreeNode* node, bool isLeft, int steps) {
        if (node == nullptr) return;

        maxPath = max(maxPath, steps);

        if (isLeft) {
            dfs(node->right, false, steps + 1);
            dfs(node->left, true, 1);
        } else {
            dfs(node->left, true, steps + 1);
            dfs(node->right, false, 1);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);

        return maxPath;
    }
};