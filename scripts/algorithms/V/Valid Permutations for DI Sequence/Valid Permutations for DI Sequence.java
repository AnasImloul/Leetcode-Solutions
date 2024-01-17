// Runtime: 3 ms (Top 88.89%) | Memory: 42.50 MB (Top 24.07%)

class Solution {
	public int numPermsDISequence(String s) {
		int length = s.length();
		int mod = 1000000007;
		int[] dp1 = new int[length + 1];
		int[] dp2 = new int[length];
		for (int j = 0; j <= length; j++) {
			dp1[j] = 1;
		}
		for (int i = 0; i < length; i++) {
			if (s.charAt(i) == 'I') {
				for (int j = 0, curr = 0; j < length - i; j++) {
					dp2[j] = curr = (curr + dp1[j]) % mod;
				}
			} else {
				for (int j = length - i - 1, curr = 0; j >= 0; j--) {
					dp2[j] = curr = (curr + dp1[j + 1]) % mod;
				}
			}
			dp1 = Arrays.copyOf(dp2, length);
		}
		return dp1[0];
	}
}
