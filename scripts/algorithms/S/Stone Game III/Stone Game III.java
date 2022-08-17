class Solution {
	Integer[] dp;

	public String stoneGameIII(int[] stoneValue) {
		dp = new Integer[stoneValue.length + 1];
	
			Arrays.fill(dp, null);
		
		int ans = stoneGameIII(0, stoneValue);
		if (ans == 0)
			return "Tie";
		else if (ans > 0)
			return "Alice";
		else
			return "Bob";
	}

	public int stoneGameIII(int l, int[] s) {
		if (l >= s.length)
			return 0;
		if (dp[l] != null)
			return dp[l];
		int ans;
			ans = Integer.MIN_VALUE;
			if (l < s.length) {
				ans = Math.max(ans, s[l] - stoneGameIII(l + 1, s));
			}
			if (l + 1 < s.length) {
				ans = Math.max(ans, s[l] + s[l + 1] -stoneGameIII(l + 2, s));
			}
			if (l + 2 < s.length) {
				ans = Math.max(ans, s[l] + s[l + 1] +s[l + 2] -stoneGameIII(l + 3, s));
			}
		 
		return dp[l] = ans;
	}
}
