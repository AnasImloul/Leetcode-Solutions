class Solution {
    public long maximumBeauty(int[] flowers, long newFlowers, int target, int full, int partial) {
        int n = flowers.length;
        long[] prefix = new long[n + 1];
        Arrays.sort(flowers);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + Math.min(flowers[i], target);
        long res = 0;
        for (int c = 0, i = n - 1; c <= n; ++c) {
            long remain = prefix[n] - prefix[n - c] + newFlowers - c * (long) target, min = 0;
            if (0 > remain) break;
            i = Math.min(i, n - c - 1);
            while (0 <= i && (target <= flowers[i] || flowers[i] * (long) (i + 1) - prefix[i + 1] > remain)) i--;
            if (0 <= i) {
                long dif = flowers[i] * (long) (i + 1) - prefix[i + 1];
                min = Math.min(target - 1, flowers[i] + (remain - dif) / (i + 1));
                if (i + 1 < n - c) min = Math.min(min, flowers[i + 1]);
            }
            res = Math.max(res, c * (long) full + min * (long) partial);
        }
        return res;
    }
}
