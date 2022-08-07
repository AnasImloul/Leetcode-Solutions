class Solution {
    public int searchInsert(int[] nums, int target) {
        int index = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                index = i;
                break;
            }
            else if(nums[i]>=target){
                index = i;
                break;
            }
            else{
                index = i+1;
            }
        }
        return index;
    }
}
