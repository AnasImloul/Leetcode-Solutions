// Runtime: 0 ms (Top 100.0%) | Memory: 49.90 MB (Top 64.7%)

class Solution {
    public int singleNonDuplicate(int[] nums) {
        if(nums.length==1) return nums[0];
        int l = 0;
        int h = nums.length-1;
        
        while(l<h){
            int mid = l+(h-l)/2;      // divide the array
            
            if(nums[mid]==nums[mid+1]) mid = mid-1;      //two same elements should be in same half
            
            if((mid-l+1)%2!=0) h = mid;            // checking the length of left half. If its is odd then update ur right pointer to mid
            
            else l = mid+1;    // else your right half will be odd then update your left pointer to mid+1
        }
        
        return nums[l];     //left pointer will have the answer at last
    }
}