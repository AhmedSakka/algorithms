def threeSum(self, nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    result = []
    nums.sort()
    for i in range(len(nums)):
        if nums[i] > 1:
            break
        if i == 0 or nums[i - 1] != nums[i]:
            self.twoSum(i, nums, result)
            
    return result
    
def twoSum(self, i, nums, result):
    low, high = i + 1, len(nums) - 1
        
    while low < high:
        if nums[i] + nums[low] + nums[high] < 0:
            low += 1
        elif nums[i] + nums[low] + nums[high] > 0:
            high -= 1
        else:
            result.append([nums[i], nums[low], nums[high]])
            low += 1
            high -= 1
                
            while low < high and nums[low - 1] == nums[low]:
                low += 1