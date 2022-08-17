class Solution {
    public int minMaxGame(int[] nums) {
        var isMin = true;
        var n=1;
        
        while(n<nums.length) {
            
            for(int i=0; i<nums.length; i+= n*2) {
                nums[i] = isMin ?
                    Math.min(nums[i], nums[i+n]) : 
                    Math.max(nums[i], nums[i+n]);
                isMin = !isMin;
            }
            
            n *= 2;
        }
        
        return nums[0];
        
    }
}
