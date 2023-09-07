// Runtime: 16 ms (Top 72.7%) | Memory: 43.76 MB (Top 33.3%)

class Solution {
    Integer[][][][] dp;
    int mod = 1000000007;
    int[] lps;
    private int add(int a, int b) {
        return (a % mod + b % mod) % mod;
    }
    private int solve(char[] s1, char[] s2, int cur, boolean isStrictLower, boolean isStrictUpper, char[] evil, int evI) {
        if(evI == evil.length) return 0;
        if(cur == s2.length) return 1;
        if(dp[cur][isStrictLower ? 1 : 0][isStrictUpper ? 1 : 0][evI] != null) return dp[cur][isStrictLower ? 1 : 0][isStrictUpper ? 1 : 0][evI];
        char start = isStrictLower ? s1[cur] : 'a';
        char end = isStrictUpper ? s2[cur] : 'z';
        int res = 0;
        for(char ch = start; ch <= end; ch ++) {
            if(evil[evI] == ch)
                res = add(res, solve(s1, s2, cur + 1, isStrictLower && ch == start, isStrictUpper && ch == end, evil, evI + 1));
            else {
                int j = evI;
                while (j > 0 && evil[j] != ch) j = lps[j - 1];
                if (ch == evil[j]) j++;
                res = add(res, solve(s1, s2, cur + 1, isStrictLower && ch == start, isStrictUpper && ch == end, evil, j));
            }
        }
        return dp[cur][isStrictLower ? 1 : 0][isStrictUpper ? 1 : 0][evI] = res;
    }
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        char[] arr = s1.toCharArray();
        char[] brr = s2.toCharArray();
        char[] crr = evil.toCharArray();
        lps = new int[crr.length];
        for (int i = 1, j = 0; i < crr.length; i++) {
            while (j > 0 && crr[i] != crr[j]) j = lps[j - 1];
            if (crr[i] == crr[j]) lps[i] = ++j;
        }
        dp = new Integer[n][2][2][crr.length];
        return solve(arr, brr, 0, true, true, crr, 0);
    }
}