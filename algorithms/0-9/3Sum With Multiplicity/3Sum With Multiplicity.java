class Solution {
    public int threeSumMulti(int[] arr, int target) {
        long[] cnt = new long[101];
        long res = 0;
        for (int i : arr) {
            cnt[i]++;
        }
        for (int i = 0; i < 101 && i <= target; i++) {
            if (cnt[i] == 0) {
                continue;
            }
            for (int j = i; j < 101 && i + j <= target; j++) {
                int k = target - i - j;
                if (k < j) {
                    break;
                }
                if (cnt[j] == 0 || k >= 101 || cnt[k] == 0) {
                    continue;
                }
                if (i == j && j == k) {
                    res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 3 / 2;
                } else if (i == j) {
                    res += cnt[k] * cnt[j] * (cnt[j] - 1) / 2;
                } else if (j == k) {
                    res += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
                } else {
                    res += cnt[i] * cnt[j] * cnt[target - i - j];
                }
            }
        }
        return (int) (res % (Math.pow(10, 9) + 7));
    }
}
