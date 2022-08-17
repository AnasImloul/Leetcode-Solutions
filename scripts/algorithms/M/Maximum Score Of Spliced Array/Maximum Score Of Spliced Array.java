class Solution {

    public int maximumsSplicedArray(int[] nums1, int[] nums2) {
        int ans = 0, sum1 = 0, sum2 = 0;

        for (int i : nums1) sum1 += i;
        for (int i : nums2) sum2 += i;

        ans = Math.max(sum1, sum2);

        int first = 0, second = 0, max1 = 0, max2 = 0;

        for (int i = 0; i < nums1.length; i++) {
            first += (nums2[i] - nums1[i]);
            second += (nums1[i] - nums2[i]);
            
            max1 = Math.max(max1, first);
            max2 = Math.max(max2, second);
            
            if (first < 0) first = 0;
            if (second < 0) second = 0;
        }

        ans = Math.max(ans, sum1 + max1);
        ans = Math.max(ans, sum2 + max2);

        return ans;
    }
}
