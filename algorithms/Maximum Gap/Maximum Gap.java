class Solution {
    public int maximumGap(int[] nums) {
        Arrays.sort(nums);
        int res=0;
        if(nums.length==0){
            return 0;
        }
        for (int i =0;i<nums.length-1;i++){
            res=Math.max(Math.abs(nums[i]-nums[i+1]),res);
        }
        return res;
    }
}


