# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if not root: return result
            
        bfs_queue = deque([root])
        
        # 0 -> left, 1 -> right
        direction = 0
        level = 0
        
        while bfs_queue:
            result.append(deque())
            
            for i in range(len(bfs_queue)):
                node = bfs_queue.popleft()
                if direction == 1:
                    result[level].appendleft(node.val)
                else:
                    result[level].append(node.val)
                    
                if node.left:
                    bfs_queue.append(node.left)
                if node.right:
                    bfs_queue.append(node.right)
                    
            level += 1
            direction = not direction
        
        return result