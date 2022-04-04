class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        product_left, product_right = [1] * len(nums), [1] * len(nums)
        
        for i in range(1, len(product_left)):
            product_left[i] = nums[i - 1] * product_left[i - 1]
        
        for i in reversed(range(len(product_right) - 1)):
            product_right[i] = nums[i + 1] * product_right[i + 1]
        
        result = []
        for i in range(len(nums)):
            result.append(product_left[i] * product_right[i])
        
        return result