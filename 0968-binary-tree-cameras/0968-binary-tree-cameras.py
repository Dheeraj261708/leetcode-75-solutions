# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minCameraCover(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        self.c = 0
        def f(node):
            if not node:
                return 2  
            left = f(node.left)
            right = f(node.right)
            if left == 0 or right == 0:
                self.c += 1
                return 1
            if left == 1 or right == 1:
                return 2
            return 0
        if f(root) == 0:
            self.c += 1

        return self.c
        