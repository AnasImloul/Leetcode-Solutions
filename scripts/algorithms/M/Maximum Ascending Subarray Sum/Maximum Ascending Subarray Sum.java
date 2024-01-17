// Runtime: 0 ms (Top 100.0%) | Memory: 41.10 MB (Top 28.39%)

class Solution {
    public int maxAscendingSum(int[] nums) {
        int res = nums[0],temp = nums[0];
        for(int i = 1;i<nums.length;i++){
            if(nums[i] > nums[i-1])
                temp+=nums[i];
            else
                temp = nums[i];
            res = Math.max(res,temp);
        }
        return res;
    }
}
