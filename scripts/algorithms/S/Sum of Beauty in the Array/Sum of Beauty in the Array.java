// Runtime: 9 ms (Top 73.89%) | Memory: 94 MB (Top 67.52%)
class Solution {
    public int sumOfBeauties(int[] nums) {
        boolean[] left = new boolean[nums.length];
        boolean[] right = new boolean[nums.length];

        left[0] = true;
        int leftMax = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] > leftMax) {
                left[i] = true;
                leftMax = nums[i];
            }
        }

        right[nums.length-1] = true;
        int rightMin = nums[nums.length-1];
        for(int i = nums.length-2; i >= 0; i--) {
            if(nums[i] < rightMin) {
                right[i] = true;
                rightMin = nums[i];
            }
        }

        int beautyCount = 0;
        for(int i = 1; i < nums.length-1; i++) {
            if(left[i] && right[i]) {
                beautyCount += 2;
            }

            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                beautyCount += 1;
            }

        }
        return beautyCount;
    }
}