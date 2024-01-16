// Runtime: 7 ms (Top 85.13%) | Memory: 42.60 MB (Top 48.1%)

/**
 * Time O(n)
 * Space O(26)
 */
class Solution {
  public int characterReplacement(String s, int k) {
    // Space O(26)
    int[] dic = new int[26];
    int start = 0;
    int maxLen = 0;
    // Time O(n)
    for (int end = 0; end < s.length(); end++) {
      maxLen = Math.max(maxLen, ++dic[s.charAt(end) - 'A']);
      if (end - start + 1 > maxLen + k) {
        dic[s.charAt(start) - 'A']--;
        start++;
      }
    }
    return s.length() - start;
  }
}
