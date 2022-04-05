# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def validate_tree(self, node, low =-float('inf'), high = float('inf')):
        if not node:
            return True
        if node.val >= high or node.val <= low:
            return False
        
        return self.validate_tree(node.left, low, node.val) and self.validate_tree(node.right, node.val, high)
        
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.validate_tree(root)