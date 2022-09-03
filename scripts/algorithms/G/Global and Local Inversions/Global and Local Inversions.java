// Runtime: 4 ms (Top 34.63%) | Memory: 77.1 MB (Top 70.64%)
class Solution {
    public boolean isIdealPermutation(int[] nums) {

        for(int i=0;i<nums.length;i++){
            if(Math.abs(nums[i]-i)>1) return false;
        }

        return true;
    }
}