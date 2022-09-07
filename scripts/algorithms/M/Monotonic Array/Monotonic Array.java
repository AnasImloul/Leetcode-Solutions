// Runtime: 4 ms (Top 51.45%) | Memory: 92.5 MB (Top 78.69%)
class Solution {
    public boolean isMonotonic(int[] nums) {
        if(nums[0]<nums[nums.length-1]){
            for(int i=0;i<nums.length-1;i++){
            if(!(nums[i]<=nums[i+1])) return false;
        }
        }else{
            for(int i=0;i<nums.length-1;i++){
            if(!(nums[i]>=nums[i+1])) return false;
        }
        }
        return true;
    }
}