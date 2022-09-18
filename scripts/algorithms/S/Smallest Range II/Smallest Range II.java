// Runtime: 39 ms (Top 5.74%) | Memory: 50.2 MB (Top 6.63%)
class Solution {
    public int smallestRangeII(int[] nums, int k) {
        int n = nums.length;
        if (n==1)
            return 0; // Max and min are the same

        Arrays.sort(nums);

        // score = minimum(max-min)
        // To minimize the score, need to add k to small numbers (Initial part of array)
        // and need to subtract k from large numbers (End part of array)

        // It might happen that when we add k to a number
        // And subtract k from another number
        // The minimum and maximum can change

        // If k>=nums[n-1]-nums[0] the score will always increase if we add k to some
        // numbers and subtract k from some numbers
        // Hence, the minimum score is the current score

        if (k >= nums[n-1]-nums[0]) {
            return nums[n-1]-nums[0];
        }

        // Now k < nums[n-1]-nums[0]
        // Add k to first p numbers and subtract k from remaining numbers
        // LEFT SEGMENT: First p numbers where we add k
        // RIGHT SEGMENT: Remaining numbers where we subtract k

        // LEFT SEGMENT: (nums[0]+k,nums[1]+k,......,nums[p-1]+k)
        // RIGHT SEGMENT: (nums[p]-k,nums[p+1]-k,.......nums[n-1]-k)

        // Question: Where is p?
        // Answer: We try all possible values for p and min score everytime

        // After subtracting and adding k to numbers,
        // the new minimum and maximum will be
        // minimum = min (nums[0]+k , nums[p]-k)
        // maximum = max (nums[p-1]+k, nums[n-1]-k)

        int minScore = nums[n-1]-nums[0];
        for (int p=1;p<n;p++) {
            int min = Math.min(nums[0]+k,nums[p]-k);
            int max = Math.max(nums[p-1]+k,nums[n-1]-k);
            minScore = Math.min(minScore,max-min);
        }

        return minScore;
    }
}