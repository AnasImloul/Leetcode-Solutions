class Solution {
    public int minDifference(int[] nums) {
        // sort the nums
        // to gain the mini difference
        // we want to remove the three smallest or biggest 
        // 0 - 3
        // 1 - 2
        // 2 - 1
        // 3 - 0
        if(nums.length <= 4){
            return 0;
        }
        
        Arrays.sort(nums);
        
        int left = 0, right = 3;
        
        int res = Integer.MAX_VALUE;
        while(left <= 3){
            int mini = nums[left];
            int max = nums[nums.length - right - 1];
            res = Math.min(res, max - mini);
            
            left++;
            right--;
        }
        
        return res;
    }
}
