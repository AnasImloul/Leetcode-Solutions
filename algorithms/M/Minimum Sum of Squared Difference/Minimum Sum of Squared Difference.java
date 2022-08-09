class Solution {
    /** Algorithm
        1. Count the differences between each nums1[i] and nums2[i] and store them into an int[100_001], as nums is between 0 and 100_000.
        2. Let's look at the example of [1,4,10,12], [4,8,6,7]. k1= 1, k2 =1
             Looking at the pairs of abs diff we have 3,4,4,5.
             So a total of 16 diff points with k = 2.
             As we observe, if we use the k operations on the first pair, we can decrease 3 to 1.
             but this would only help with 3^2 (9) -> 1. So we decrease the totam sum diff by 8.
             However, if we operate on the diff of 5, this would have much more impact.
             5 - 1 => (4^2)25 - 16 . so we save 9 points by using 1 k
             5 - 2 => (3^2) 25 - 9. So we save 16 points.
         3. As we can see, we need to operate on the highest diff, lowering them.
         4. As we have counted them on step #1, we would have an array like this
           [0,0,0,1,2,1] : 1 diff of 3, 2 of 4 and 1 of 5.
         5. While k is > 0 (k1 + k2), start from the back (highest) and decrease it one group at a time.
           So make all 5 diffs into 4 diff, only if their cardinal is <= k. If it's greater than k, we can only
           lower k diff to diff -1.
           So [0,0,0,1,2,1] and k = 2 => [0,0,0,1,3,0] and k =1
           We have 3 diff of 4 and just k =1 so we can turn one 4 into a 3.
           => [0,0,0,2,2,0]. Thus. the diff becomes 2 of 3 and 2 of 4.
    */
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        long minSumSquare = 0;
        int[] diffs = new int[100_001];
        long totalDiff = 0;
        long kSum = k1 + k2;
        int currentDiff;
        int maxDiff = 0;
        for (int i = 0; i < nums1.length; i++) {
            // get current diff.
            currentDiff = Math.abs(nums1[i] - nums2[i]);
            // if current diff > 0, count/store it. If not,then ignore it.
            if (currentDiff > 0) {
                totalDiff += currentDiff;
                diffs[currentDiff]++;
                maxDiff = Math.max(maxDiff, currentDiff);
            }
        }
        // if kSum (k1 + k2) < totalDifferences, it means we can make all numbers/differences 0s
        if (totalDiff <= kSum) {
            return 0;
        }
        // starting from the back, from the highest difference, lower that group one by one to the previous group.
         // we need to make all n diffs to n-1, then n-2, as long as kSum allows it.
        for (int i = maxDiff; i> 0 && kSum > 0; i--) {
            if (diffs[i] > 0) {
                // if current group has more differences than the totalK, we can only move k of them to the lower level.
                if (diffs[i] >= kSum) {
                    diffs[i] -= kSum;
                    diffs[i-1] += kSum;
                    kSum = 0;
                } else {
                    // else, we can make this whole group one level lower.
                    diffs[i-1] += diffs[i];
                    kSum -= diffs[i];
                    diffs[i] = 0;
                }
            }
        }

        for (int i = 0; i <= maxDiff; i++) {
            if (diffs[i] > 0) {
                minSumSquare += (long) (Math.pow((long)i, 2)) * diffs[i];
            }
        }
        return minSumSquare;
    }
}
