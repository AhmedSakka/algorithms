public int[] twoSum(int[] nums, int target) {
    HashMap<Integer, Integer> numbersMap = new HashMap<>();
    for(int i = 0; i < nums.length; i++){
        numbersMap.put(nums[i], i);
    }
    for(int i = 0; i < nums.length; i++){
        if(numbersMap.containsKey(target - nums[i]) && numbersMap.get(target - nums[i]) != i){
            return new int[] {i, numbersMap.get(target - nums[i])};
        }
    }
    return null;
}