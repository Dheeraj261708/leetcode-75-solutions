# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        if not root:
            return None
        q=[root]
        while q:
            node=q.pop(0)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
            node.left,node.right=node.right,node.left
        return root