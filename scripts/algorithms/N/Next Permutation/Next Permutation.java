// Runtime: 1 ms (Top 91.93%) | Memory: 43.7 MB (Top 52.39%)

class Solution {
    public void nextPermutation(int[] nums) {
        // FIND peek+1
        int nextOfPeak = -1;
        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                nextOfPeak = i - 1;
                break;
            }
        }

        // Return reverse Array
        if (nextOfPeak == -1) {
            int start = 0;
            int end = nums.length - 1;
            while (start <= end) {
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
            return;
        }
        // Find element greater than peek
        int reversalPoint = nums.length - 1;
        for (int i = nums.length - 1; i > nextOfPeak; i--) {
            if (nums[i] > nums[nextOfPeak]) {
                reversalPoint = i;
                break;
            }
        }

        // swap nextOfPeak && reversalPoint
        int temp = nums[nextOfPeak];
        nums[nextOfPeak] = nums[reversalPoint];
        nums[reversalPoint] = temp;

        // Reverse array from nextOfPeak+1
        int start = nextOfPeak + 1;
        int end = nums.length - 1;
        while (start <= end) {
            int temp1 = nums[start];
            nums[start] = nums[end];
            nums[end] = temp1;
            start++;
            end--;
        }

    }
}