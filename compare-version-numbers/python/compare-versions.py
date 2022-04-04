class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1_list = version1.split(".")
        v2_list = version2.split(".")
        
        max_len = max(len(v1_list), len(v2_list))
        
        for i in range(max_len):
            v1, v2 = '0', '0'
            
            if i < len(v1_list):
                v1 = v1_list[i]
            if i < len(v2_list):
                v2 = v2_list[i]
                
            while len(v1) > 1 and v1[0] == '0':
                v1 = v1[1:]
            while len(v2) > 1 and v2[0] == '0':
                v2 = v2[1:]
            
            if int(v1) > int(v2):
                return 1
            elif int(v2) > int(v1):
                return -1
            else:
                continue
        
        return 0