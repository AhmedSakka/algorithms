def twoSum(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    numbersMap = {}
    for i in range(len(nums)):
        numbersMap[nums[i]] = i
        
    for i in range(len(nums)):
        complement = target - nums[i]
        if complement in numbersMap and numbersMap[complement] != i:
            return [i, numbersMap[complement]]
        
    return []