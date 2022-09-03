// Runtime: 50 ms (Top 49.30%) | Memory: 48.5 MB (Top 48.18%)
class Solution {
    public int longestIdealString(String s, int k) {
        int DP[] = new int[26], ans = 1;

        for (int ch = 0, n = s.length(); ch < n; ch++) {
            int i = s.charAt(ch) - 'a';
            DP[i] = DP[i] + 1;

            for (int j = Math.max(0, i - k); j <= Math.min(25, i + k); j++)
                if (j != i)
                    DP[i] = Math.max(DP[i], DP[j] + 1);

            ans = Math.max(ans, DP[i]);
        }

        return ans;
    }
}