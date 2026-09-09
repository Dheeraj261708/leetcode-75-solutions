# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        result = []
        
        def dfs(node, current_path, remaining_sum):
            if not node:
                return
            current_path.append(node.val)
            if not node.left and not node.right and remaining_sum == node.val:
                result.append(list(current_path))
            else:
                dfs(node.left, current_path, remaining_sum - node.val)
                dfs(node.right, current_path, remaining_sum - node.val)
            current_path.pop() 
        dfs(root, [], targetSum)
        return result
        