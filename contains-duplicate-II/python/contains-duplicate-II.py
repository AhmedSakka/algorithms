def containsNearbyDuplicate(nums, k):

    nums_set = set()
    for i,num in enumerate(nums):
        if num in nums_set:
            return True
        nums_set.add(num)
        if len(nums_set) > k:
            nums_set.remove(nums[i - k])
    return False

test_input_list = [1,2,3,1]
k = 3

if containsNearbyDuplicate(test_input_list, k) == True :
    print("The list contains nearby duplicate!")
else:
    print("The list doesn't contain nearby duplicate!")
