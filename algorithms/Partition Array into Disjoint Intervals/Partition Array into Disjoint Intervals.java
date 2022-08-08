class Solution {
    public int partitionDisjoint(int[] nums) {
        int mts = nums[0]; // max till scan
        int mtp = nums[0]; // max till partition
        int idx = 0;
        
        for(int i=1; i<nums.length; i++) {
            int val = nums[i];
            if(val < mtp) {
                idx = i;
                mtp = mts;
            }
            
            mts = Math.max(mts, val);
        }
        
        return idx + 1;
    }
}
