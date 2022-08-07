class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int min = 1;
        
        for (int ele : nums) {
            if(ele == min) {
                min++;
            }
        }
        return min;
    }
}

// TC: O(n) + O(n * logn) --> O(n * logn),  SC: O(1)
