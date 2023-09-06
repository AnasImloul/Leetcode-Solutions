// Runtime: 0 ms (Top 100.0%) | Memory: 44.51 MB (Top 6.9%)

class Solution {
    public int maximumCount(int[] nums) {
        int positive_count = 0;
        int negative_count = 0;

        for(int i=0; i<nums.length; i++){
            if(nums[i] > 0){
                positive_count++;
            }
            else if(nums[i] < 0){
                negative_count++;
            }
        }
        return (positive_count > negative_count) ? positive_count:negative_count;
    }
}