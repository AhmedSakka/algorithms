class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        heights_stack = []
        ans, current = 0, 0
        
        while current < len(height):
            while heights_stack and height[current] > height[heights_stack[-1]]:
                current_bar = heights_stack.pop()
                if not heights_stack:
                    break
                distance = current - heights_stack[-1] - 1
                h = min(height[current], height[heights_stack[-1]]) - height[current_bar]
                ans += distance * h
            heights_stack.append(current)
            current += 1
        return ans