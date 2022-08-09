class Solution {
    public int waysToSplitArray(int[] nums) {
        long sum = 0;
        for(int i : nums){
            sum+=i;
        }
        int sol = 0;
        long localSum = 0;
        for(int i=0; i<nums.length-1;i++){
            localSum += nums[i];
            if(localSum >= sum-localSum){
                sol++;
            }
        }
        return sol;
    }
}