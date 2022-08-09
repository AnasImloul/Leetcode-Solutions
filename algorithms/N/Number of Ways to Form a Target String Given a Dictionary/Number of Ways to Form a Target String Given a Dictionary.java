class Solution {
    public int numWays(String[] words, String target) {
        int[][] indexCharCount = new int[words[0].length()][26];
        int[][] dp = new int[words[0].length()][target.length()];
        for (int[] ar : dp)
            Arrays.fill(ar, -1);
        for (String word : words) {
            for (int i = 0; i < word.length(); i++)
                indexCharCount[i][word.charAt(i) - 'a']++;
        }
        
        return waysHelper(indexCharCount, 0, target, 0, dp);
    }
    
    private int waysHelper (int[][] indexCharCount, int wordIndex, String target, int targetIndex, int[][] dp) {
        long count = 0;
        if (targetIndex == target.length())
            return 1;
        if (wordIndex == indexCharCount.length)
            return 0;
        
        if (dp[wordIndex][targetIndex] != -1)
            return dp[wordIndex][targetIndex];
        
        for (int i = wordIndex; i < indexCharCount.length; i++) {
            if (indexCharCount[i][target.charAt(targetIndex) - 'a'] > 0)
                count += indexCharCount[i][target.charAt(targetIndex) - 'a'] * (long)waysHelper(indexCharCount, i+1, target, targetIndex+1, dp);
            count = count % 1000000007;
        }
       
        return dp[wordIndex][targetIndex] = (int)count;
        
    }
}
