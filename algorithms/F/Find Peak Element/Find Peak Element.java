class Solution {
    public int findPeakElement(int[] nums) {
       int start = 0;
       int end = nums.length - 1;
        
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid + 1]){
                //It means that we are in decreasing part of the array
                end = mid;
            }
            else{
                //It means that we are in increasing part of the array
                start = mid + 1;
            }
        }
        return start;
    }
}
