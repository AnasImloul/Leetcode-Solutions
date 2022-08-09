class Solution {
	static int[][] dp;

	public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
		dp = new int[k + 1][profits.length + 1];
		for (int[] row : dp) {
			Arrays.fill(row, -1);
		}
		return w + help(k, w, 0, profits, capital);
	}

	public int help(int k, int w, int i, int[] profits, int[] capital) {
		if (k == 0 || i >= profits.length)
			return 0;
		if (dp[k][i] != -1)
			return dp[k][i];
		int res = Integer.MIN_VALUE;
		if (capital[i] <= w) {
			res = Math.max(res, Math.max(profits[i] + help(k - 1, w + profits[i], i + 1, profits, capital),
					help(k, w, i + 1, profits, capital)));
		} else {
			res = Math.max(res, help(k, w, i + 1, profits, capital));
		}
		return dp[k][i] = res;
	}
}
