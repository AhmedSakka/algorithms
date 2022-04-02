class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == "":
            return 0

        for i in range(len(haystack)):
            if haystack[i] == needle[0]:
                _i, _j = i + 1, 1
                while _i < len(haystack) and _j < len(needle) and haystack[_i] == needle[_j]:
                    _i += 1
                    _j += 1
                if _j == len(needle):
                    return i
        return -1