# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    max_sum = -float('inf')
    
    def maxOutcome(self, node):
        if not node: return 0
        
        maxLeft = max(self.maxOutcome(node.left), 0)
        maxRight = max(self.maxOutcome(node.right), 0)
        current_sum = node.val + maxLeft + maxRight
        self.max_sum = max(current_sum, self.max_sum)
        
        return node.val + max(maxLeft, maxRight)
        
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxOutcome(root)
        return self.max_sum