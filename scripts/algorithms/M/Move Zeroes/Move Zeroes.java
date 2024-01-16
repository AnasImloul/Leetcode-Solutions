// Runtime: 1 ms (Top 100.0%) | Memory: 46.20 MB (Top 23.08%)

class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0; 
        for (int num:nums){
            if(num != 0){
                nums[i] = num;
                i++;
            }
        }
        while(i<nums.length){
            nums[i] = 0;
            i++;
        }
    }
}
