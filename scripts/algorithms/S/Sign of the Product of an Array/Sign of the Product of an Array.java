class Solution {
    public int arraySign(int[] nums) {
        int prod=1;
        for(int i=0;i<nums.length;i++){
            int val=signFunc(nums[i]);
            prod*=val;
        }
        return prod;
    }
    
    private int signFunc(int x){
        if(x<0) return -1;
        else if(x>0) return 1;
        return 0;
    }
}
