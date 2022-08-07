class Solution {
    
    //  Time Complexity = O(N)
    //  Space Complexity = O(1)
    
    public int removeDuplicates(int[] nums) {
        
        //  Base Condition
        if (nums.length <= 1) 
            return nums.length;
        
        int i = 1, j = 1;
        
        while (j < nums.length) {
            if (nums[j] != nums[i-1]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i ;
    }
}
