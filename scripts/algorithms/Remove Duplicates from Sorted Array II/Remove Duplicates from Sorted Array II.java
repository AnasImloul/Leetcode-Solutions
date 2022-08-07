class Solution {
    public int removeDuplicates(int[] nums) {
       int count = 2,len =nums.length ;
       for(int i=2;i<len;i++){
           if(nums[i]!=nums[count-2]){
               nums[count]=nums[i];
               count++;
           }
       } 
       return count;
    }
}
