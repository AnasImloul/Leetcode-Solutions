// Runtime: 12 ms (Top 37.13%) | Memory: 169.4 MB (Top 17.70%)
// Time complexity = 2n = O(n)
// Space complexity = O(1), or O(n) if the result array is including in the complexity analysis.

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] result = new int[nums.length];
        int left = 0, right = nums.length - 1;

        for(int i = 0; i < nums.length; i++) {
            if(nums[i] < pivot) {
                result[left++] = nums[i];
            }
            if(nums[nums.length - 1 - i] > pivot) {
                result[right--] = nums[nums.length - 1 - i];
            }
        }

        while(left <= right) {
            result[left++] = pivot;
            result[right--] = pivot;
        }

        return result;
    }
}