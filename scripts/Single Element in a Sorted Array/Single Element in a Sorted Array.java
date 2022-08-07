class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int left = 0;
        int right = nums.length-1;
        
        while(left < right){
            
            int mid = (left+right)/2;
            
            if(nums[mid] == nums[mid+1]){
                mid = mid - 1;                   //two same elements should be in same half
            }
            
            if((mid-left+1)%2 != 0){
                right = mid;                     // checking the length of left half. 
                                                //If its is odd then update ur right pointer to mid
            }else{
                left = mid + 1;                  // else your right half will be odd 
                                                //then update your left pointer to mid+1

            }
        }
        
        return nums[left];                  //left pointer will have the answer at last 
    }
}
