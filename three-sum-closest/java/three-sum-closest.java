class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int result = target, diff = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++){
            int low = i + 1, high = nums.length - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum > target){
                    high--;
                } else if (sum < target){
                    low++;
                } else {
                    return sum;
                }
                if(Math.abs(target - sum) < Math.abs(diff)){
                    result = sum;
                    diff = target - sum;
                }
            }

        }
        return result;
    }
}