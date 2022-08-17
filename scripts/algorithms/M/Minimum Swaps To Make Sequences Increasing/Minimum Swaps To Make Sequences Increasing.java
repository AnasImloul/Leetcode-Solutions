class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int p1 = nums1[0], p2 = nums2[0], ans = 0;
        int len = nums1.length, s = 0, count = 0;
        for (int i=1; i < len; i++) {
            int n1 = nums1[i], n2 = nums2[i];
            if (n1 > p1 && n2 > p2) {
                if (n1 > p2 && n2 > p1) {
                    ans += Math.min(count, i - s - count);
                    s = i; count = 0;
                }
                p1 = n1; p2 = n2;
            } else {
                count++;
                p1 = n2; p2 = n1;
            }
        }
        return ans + Math.min(count, len - s - count);
    }
}
