// Runtime: 2 ms (Top 91.14%) | Memory: 57.8 MB (Top 74.85%)
class Solution {
   public int firstMissingPositive(int[] nums) {
       //cyclic sort
        int i = 0;
        while (i<nums.length){
            int correct = nums[i]-1;
            if(nums[i]>0 && nums[i]<=nums.length && nums[i]!=nums[correct]){
                swap(nums,i,correct);
            }else{
                i++;
            }
        }
       //linear search to find the missing number
        for(int index=0;index<nums.length;index++){
            if (nums[index] != index+1) {
                return index+1;
            }
        }
       //if array has all the elements match to its index then 1st missing num will be
       //nums.length+1
        return nums.length+1;
    }
    static void swap(int[]arr,int a , int b){
        int temp = arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
}