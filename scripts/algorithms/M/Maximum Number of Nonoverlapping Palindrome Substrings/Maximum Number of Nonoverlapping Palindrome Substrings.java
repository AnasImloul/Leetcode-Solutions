// Runtime: 27 ms (Top 34.5%) | Memory: 40.67 MB (Top 50.1%)

class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        int[] dp = new int[n + 1];

        // Base case (redundant, but for clarity)
        dp[0] = 0;

        // Odd palindrome (center of 1 index)
        for (int i = 0; i < n; i++) {
            dp[i + 1] = Math.max(dp[i], dp[i + 1]);
            for (int j = 0; j < n; j++) {
                int left = i - j;
                int right = i + j;
                if (left < 0 || right >= n) break;
                if (s.charAt(left) != s.charAt(right)) break;

                if (right - left + 1 >= k) {
                    dp[right + 1] = Math.max(dp[right + 1], dp[left] + 1);
                }

            }

            // Even palindrome (center of 2 indexes)
            for (int j = 0; j < n; j++) {
                int left = i - j - 1;
                int right = i + j;
                if (left < 0 || right >= n) break;
                if (s.charAt(left) != s.charAt(right)) break;

                if (right - left + 1 >= k) {
                    dp[right + 1] = Math.max(dp[right + 1], dp[left] + 1);
                }
            }
        }

        // for (int a : dp) System.out.print(a + " ");
        return dp[n];
    }
}