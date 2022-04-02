class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        wordsDict = {}
        result = []
        
        for word in strs:
            sorted_chars = sorted(word)
            sorted_word = "".join(sorted_chars)
            if sorted_word in wordsDict:
                wordsDict[sorted_word].append(word)
            else:
                wordsDict[sorted_word] = [word]
                
        for key, val in wordsDict.items():
            result.append(val)
        
        return result