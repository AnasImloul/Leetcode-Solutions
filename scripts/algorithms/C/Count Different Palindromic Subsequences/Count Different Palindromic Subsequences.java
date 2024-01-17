// Runtime: 33 ms (Top 61.21%) | Memory: 50.70 MB (Top 75.86%)

class Solution {
    public int countPalindromicSubsequences(String str) {
        int[] pre = new int[str.length()];
		HashMap<Character, Integer> map = new HashMap<>();
		int mod = 1000000007;
		for(int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			if(map.containsKey(ch))
				pre[i] = map.get(ch);
			else
				pre[i] = -1;
			map.put(ch, i);
		}
		
		int[] next = new int[str.length()];
		map = new HashMap<>();
		for(int i = str.length() - 1; i >= 0; i--) {
			char ch = str.charAt(i);
			if(map.containsKey(ch))
				next[i] = map.get(ch);
			else
				next[i] = Integer.MAX_VALUE;
			map.put(ch, i);
		}
		
		int[][] dp = new int[str.length()][str.length()];
		
		for(int g = 0; g < dp.length; g++) {
			for(int i = 0, j = g; j < dp[0].length; i++, j++) {
				if(g == 0)
					dp[i][j] = 1;
				else if(g == 1)
					dp[i][j] = 2;
				else {
					if(str.charAt(i) == str.charAt(j)) {
						int n = next[i];
						int p = pre[j];
						
						if(n > p)
							dp[i][j] = ((2 * dp[i+1][j-1]) + 2) % mod;
						else if(n == p)
							dp[i][j] = ((2 * dp[i+1][j-1]) + 1) % mod;
						else
							dp[i][j] = ((2 * dp[i+1][j-1]) - dp[n+1][p-1]) % mod;
					}else
						dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]) % mod;
				}
                if(dp[i][j] < 0)
                    dp[i][j] += mod;
			}
		}
		return dp[0][dp[0].length - 1] % mod;
    }
}
