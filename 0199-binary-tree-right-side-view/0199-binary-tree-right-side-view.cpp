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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& result) {
        if (!node) return;
        if (depth == result.size()) {
            result.push_back(node->val);
        }
        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
        
    }
};