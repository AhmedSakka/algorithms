class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        brackets_stack = []
        brackets_map = {")":"(", ']':'[', '}': '{'}
        
        for char in s:
            if char in brackets_map:
                if len(brackets_stack) == 0:
                    return False
                open_bracket = brackets_stack.pop()
                if brackets_map[char] != open_bracket: 
                    return False
            else:
                brackets_stack.append(char)
            
        return True if len(brackets_stack) == 0 else False