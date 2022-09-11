// Runtime: 0 ms (Top 100.00%) | Memory: 39.4 MB (Top 99.44%)
class Solution {
    public int rob(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        int[] t = new int[nums.length];
        for(int i = 0 ; i < t.length;i++){
            t[i] = -1;
        }
        int[] k = new int[nums.length];
        for(int i = 0 ; i < k.length;i++){
            k[i] = -1;
        }
        return Math.max(helper(nums,0,0,t),helper(nums,1,1,k));
    }
    static int helper(int[] nums, int i,int start , int[] t){
        if(start==0 && i==nums.length-2){
            return nums[i];
        }
        if(start==1 && i==nums.length-1){
            return nums[i];
        }
        if(start==0 && i>=nums.length-1){
            return 0;
        }
        if(start==1 && i>=nums.length){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int pick = nums[i]+helper(nums,i+2,start,t);
        int notpick = helper(nums,i+1,start,t);
        t[i] = Math.max(pick,notpick);
        return t[i];
    }
}