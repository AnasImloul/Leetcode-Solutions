class Solution {
    public int maximumXOR(int[] nums) {
        int res = 0;
        for (int i=0; i<nums.length; i++){
            res |= nums[i];
        }
        return res;
    }
}
