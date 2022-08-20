// Runtime: 0 ms (Top 100.00%) | Memory: 42.4 MB (Top 71.77%)

class Solution {
    public int removeElement(int[] nums, int val) {
        int ind = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] != val){
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
}