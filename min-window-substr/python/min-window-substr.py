class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if not s and not t:
            return ""
        
        dict_t = Counter(t)
        required = len(dict_t)
        window_dict = {}
        formed, l, r = 0, 0, 0
        
        ans = float("inf"), None, None
        
        # Expand the window
        while r < len(s):
            character = s[r]
            window_dict[character] = window_dict.get(character, 0) + 1
            
            if character in dict_t and window_dict[character] == dict_t[character]:
                formed += 1
                
            # Contract the window
            while l <= r and formed == required:
                character = s[l]
                
                # Update current answer tuple
                if ans[0] > r - l + 1:
                    ans = (r - l + 1, l, r);
                
                window_dict[character] -= 1
                
                if character in dict_t and window_dict[character] < dict_t[character]:
                    formed -= 1
                l += 1
                
            r += 1
            
        return "" if ans[0] == float("inf") else s[ans[1]: ans[2] + 1]