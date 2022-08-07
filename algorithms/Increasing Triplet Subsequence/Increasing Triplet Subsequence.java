class Solution {
    public boolean increasingTriplet(int[] nums) {
        if(nums.length < 3)
            return false;
        
        int x = Integer.MAX_VALUE;
        int y = Integer.MAX_VALUE;
        
        for (int i : nums){
            if(i <= x){
                x = i;
            }else if (i <= y)
                y = i;
            else 
                return true;
        }
        
        return false;
    }
}
