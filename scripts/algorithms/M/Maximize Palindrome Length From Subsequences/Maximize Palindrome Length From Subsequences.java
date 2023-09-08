// Runtime: 545 ms (Top 8.4%) | Memory: 230.95 MB (Top 8.4%)

class Solution {
    public int longestPalindrome(String word1, String word2) {
        String lWord = word1 + word2;
        return palindrome(lWord, 0, lWord.length()-1, word1.length(), false, 
                          new int[lWord.length()][lWord.length()][2]);
    }
    
    private int palindrome(String word, int start, int end, int boundary, boolean isFound, int[][][] dp) {
        if ((!isFound && (start >= boundary || end < boundary)) || (start > end))
            return 0;
        
        if (dp[start][end][isFound?0:1] != 0)
            return dp[start][end][isFound?0:1];
        
        return dp[start][end][isFound?0:1] = word.charAt(start) == word.charAt(end) ? 
            ((start == end ? 1: 2) + palindrome(word, start+1, end-1, boundary, true, dp)) : 
                Math.max(palindrome(word, start+1, end, boundary, isFound, dp), 
                         palindrome(word, start, end-1, boundary, isFound, dp));
    }
}
