// One Pass Counting Solution
// 1. check cur-prev == 1 or -25 to track the length of longest continuos subtring.
// 2. counts to track the longest continuos subtring starting with current character.
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
    public int findSubstringInWraproundString(String p) {
        final int N = p.length();
        int res = 0, len = 1;
        int[] counts = new int[26];
        for (int i = 0; i < N; i++) {
            char ch = p.charAt(i);
            if (i > 0 && (ch - p.charAt(i-1) == 1 || ch - p.charAt(i-1) == -25)) {
                len++;
            } else {
                len = 1;
            }
            int idx = ch - 'a';
            counts[idx] = Math.max(counts[idx], len);
        }
        for (int count : counts) {
            res += count;
        }
        return res;
    }
}
