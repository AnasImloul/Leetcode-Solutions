class Solution {
    public int firstDayBeenInAllRooms(int[] nextVisit) {
        int rooms = nextVisit.length;
        long dp[] = new long[rooms];
        int mod = (int)(1e9)+7;
        for (int i=1 ; i<rooms ; i++) {
            if (nextVisit[i-1] == i-1)
                dp[i] = dp[i-1]+2;
            else
                dp[i] = (dp[i-1] + dp[i-1] - dp[nextVisit[i-1]] + 2 + mod)%mod;
        }
        return (int)dp[rooms-1];
    }
}
