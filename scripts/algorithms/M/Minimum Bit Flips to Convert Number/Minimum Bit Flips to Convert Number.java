class Solution {
	public static int minBitFlips(int a1, int a2) {
		int n = (a1 ^ a2);
		int res = 0;
		while (n != 0) {
			res++;
			n &= (n - 1);
		}
		return res;
	}
}