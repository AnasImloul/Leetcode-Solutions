class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        HashSet<Integer> set = new HashSet<>();
        for(int day: days) set.add(day);
        int n = days[days.length - 1];
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            if(!set.contains(i)){
                dp[i] = dp[i - 1];
                continue;
            }
            int a = dp[Math.max(0, i - 1)] + costs[0];
            int b = dp[Math.max(0, i - 7)] + costs[1];
            int c = dp[Math.max(0, i - 30)] + costs[2];
            dp[i] = Math.min(a, Math.min(b, c));
        }
        return dp[n];
    }
}