class Solution {
    public int minStartValue(int[] nums) {
        int lowest_sum = 0;
        int sum = 0;
        for(int i=0; i<nums.length; i++) {
            sum += nums[i];
            if(lowest_sum > sum) {
                lowest_sum = sum;
            }
        }
        return 1-lowest_sum;
    }
}
