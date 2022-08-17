class Solution {
    public int minDeletion(int[] nums) {
        
        int deletion = 0, n = nums.length;
        
        for (int i=0; i<n-1; ) {
            int newIndex = i-deletion;
            if ((newIndex % 2 == 0) && nums[i] == nums[i+1])   deletion++;
            else    i++;
        }
        return ((n-deletion) % 2 == 0) ? deletion : deletion+1;
    }
}
