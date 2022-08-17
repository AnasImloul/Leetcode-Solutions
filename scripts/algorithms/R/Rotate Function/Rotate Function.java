class Solution {
    public int maxRotateFunction(int[] nums) {
        int sum1 =0,sum2 = 0;
        for(int i=0;i<nums.length;i++){
            sum1 += nums[i];
            sum2 += i*nums[i];
        }
        int result = sum2;
        for(int i=0;i<nums.length;i++){
            sum2 = sum2-sum1+(nums.length)*nums[i];
            result = Math.max(result,sum2);
        }
        return result;
    }
}
