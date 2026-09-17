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
    unordered_map<long long, int> prefixSumCount;

    int dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (node == nullptr) {
            return 0;
        }
        currentSum += node->val;
        int totalPaths = prefixSumCount[currentSum - targetSum];
        prefixSumCount[currentSum]++;
        totalPaths += dfs(node->left, currentSum, targetSum);
        totalPaths += dfs(node->right, currentSum, targetSum);
        prefixSumCount[currentSum]--;

        return totalPaths;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum);
        
    }
};