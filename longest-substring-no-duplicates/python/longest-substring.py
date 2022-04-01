def lengthOfLongestSubstring(self, s):
    """
    :type s: str
    :rtype: int
    """
    if s == "":
        return 0
        
    maxLength = 1
    for i in range(len(s)):
        charDict = {s[i]: True}
        currentLength = 1
        for j in range(i + 1, len(s)):
            if s[j] in charDict:
                break
            currentLength += 1
            charDict[s[j]] = True
            maxLength = max(maxLength, currentLength)
                
    return maxLength