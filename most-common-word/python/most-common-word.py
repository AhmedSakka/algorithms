class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        banned_set = set(banned)
        paragraph_normalized = ''.join([c.lower() if c.isalnum() else ' ' for c in paragraph])
        words = paragraph_normalized.split()
        
        words_dict = {}
        for word in words:
            if word not in banned_set:
                words_dict[word] = words_dict.get(word, 0) + 1
                
        max_freq = 0
        result = ""
        
        for word in words_dict:
            if words_dict[word] > max_freq:
                max_freq = words_dict[word]
                result = word
        
        return result