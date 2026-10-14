class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(node, current_sum):
            if not node:
                return 0
            
            # Calculate the number formed up to this node
            current_sum = current_sum * 10 + node.val
            
            # If it's a leaf node, return the accumulated path sum
            if not node.left and not node.right:
                return current_sum
            
            # Otherwise, recursively sum the left and right subtrees
            return dfs(node.left, current_sum) + dfs(node.right, current_sum)
        
        return dfs(root, 0)