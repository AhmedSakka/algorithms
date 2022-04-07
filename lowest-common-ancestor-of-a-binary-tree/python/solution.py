# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    answer = None
    
    def dfs(self, node, p, q):
        if not node:
            return False
        mid = node == p or node == q
        left = self.dfs(node.left, p, q)
        right = self.dfs(node.right, p, q)
        
        if (left and right) or (left or right) and mid:
            self.answer = node
        
        return mid or left or right
    
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.dfs(root, p, q)
        return self.answer