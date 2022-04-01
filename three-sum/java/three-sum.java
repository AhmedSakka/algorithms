public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++){
                if(nums[i] > 1) break;
                        if(i == 0 || nums[i - 1] != nums[i]){
                        twoSum(i, nums, result);
                        }
                }
        return result;
}
    
private void twoSum(Integer i, int[] nums, List<List<Integer>> result){
        Integer low = i + 1, high = nums.length - 1;
        while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                        low++;
                } else if(nums[i] + nums[low] + nums[high] > 0){
                        high--;
                } else {
                        result.add(Arrays.asList(nums[i], nums[low++], nums[high--]));
                        while(low < high && nums[low - 1] == nums[low]) low++;
                }
        }
}