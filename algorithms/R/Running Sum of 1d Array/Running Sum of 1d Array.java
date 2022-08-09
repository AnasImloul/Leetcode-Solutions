class Solution {
    public int[] runningSum(int[] nums) {
        
        int [] res = new int[nums.length]; int index = 0;
        
        for(int i=0; i<nums.length; i++){
            int runSum = 0;
            for(int j=0; j<=i; j++){
                runSum += nums[j];
            }
            res[index++] = runSum;
        }
        return res;
    }
}
