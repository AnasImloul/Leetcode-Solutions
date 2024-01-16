// Runtime: 7 ms (Top 81.4%) | Memory: 45.10 MB (Top 27.91%)

// separate string s into two parts and match subsequence forward and backward separately
    class Solution {
        public int minimumScore(String s, String t) {
            int m = s.length(), n = t.length();
            int[] left = new int[m];
            for (int i = 0, j = 0; i < m; i++) {
                if (j < n && s.charAt(i) == t.charAt(j)) {
                    ++j;
                }
                left[i] = j;
            }
            int[] right = new int[m];
            for (int i = m - 1, j = n - 1; i >= 0 ; i--) {
                if (j >= 0 && s.charAt(i) == t.charAt(j)) {
                    --j;
                }
                right[i] = j;
            }
            int min = Math.min(n - left[m - 1], right[0] + 1);
            for (int i = 0; i + 1 < m; i++) {
                min = Math.min(min, Math.max(0, right[i + 1] - left[i] + 1));
            }
            return min;
        }
    }