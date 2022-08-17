class Solution {
    int ans;
    public int minOperations(int[] nums, int x) {
        ans = Integer.MAX_VALUE;
        recur(nums,0,nums.length-1,x,0);
        return ans==Integer.MAX_VALUE?-1:ans;
    }
    public void recur(int nums[],int start, int end,int target,int steps){
         if(target==0){
            ans = Math.min(ans,steps);
            return;
        }
        if(start>end || target<0){
            return;
        }
       
        recur(nums,start+1,end,target-nums[start],steps+1);
        recur(nums,start,end-1,target-nums[end],steps+1); 
    }
}
