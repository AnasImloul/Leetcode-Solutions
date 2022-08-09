class Solution {
    public int longestPalindromeSubseq(String s) {
        	StringBuilder sb = new StringBuilder(s);
    	    sb.reverse();
    	    String s2 = sb.toString();
        return longestCommonSubsequence(s,s2);
    }
     public int longestCommonSubsequence(String text1, String text2) {
        int [][]dp = new int[text1.length()+1][text2.length()+1]; 
        for(int i= text1.length()-1;i>=0;i--){
            for(int j = text2.length()-1;j>=0;j--){
                char ch1 = text1.charAt(i);
                char ch2 = text2.charAt(j);
                if(ch1==ch2) // diagnal
                dp[i][j]= 1+dp[i+1][j+1];
                else// right,down considering not matchning char from s1 and skipping s2 
                //considering not matchning char from s2 and skipping s1
                    dp[i][j] = Math.max(dp[i][j+1],dp[i+1][j]);
                    
            }
        }
        return dp[0][0];
    }
}
