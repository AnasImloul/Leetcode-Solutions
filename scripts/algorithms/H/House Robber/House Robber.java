// Runtime: 0 ms (Top 100.00%) | Memory: 41.8 MB (Top 31.47%)
class Solution {
    public int rob(int[] nums) {
        int[] t = new int[nums.length] ;
        for(int i=0; i<t.length; i++){
            t[i] =-1;
        }
       return helper(nums,0,t);
    }
    static int helper(int[] nums, int i,int[] t){
        if(i>=nums.length){
            return 0;
        }
        if(i==nums.length-1){
            return nums[i];
        }
        if(t[i] != -1){
            return t[i];
        }

        int pick = nums[i] + helper(nums,i+2,t);
        int unpicked = helper(nums,i+1,t);
        t[i] = Math.max(pick,unpicked);
        return t[i];

    }
}