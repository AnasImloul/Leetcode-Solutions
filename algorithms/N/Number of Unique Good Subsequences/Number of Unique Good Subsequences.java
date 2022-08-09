class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        int initialZeroCount= 0;
        while(initialZeroCount < binary.length() && binary.charAt(initialZeroCount) == '0') initialZeroCount++;
        if(initialZeroCount == binary.length()) return 1;
        long[] dp = new long[binary.length()];
        dp[initialZeroCount] = 1;
        int lastOne = 0, lastZero = 0;
        long mod = (long) Math.pow(10, 9)+7;
        for(int i=initialZeroCount+1;i<binary.length();i++){
            int j = binary.charAt(i) == '1' ? lastOne : lastZero;
            long dup = j > 0 ? dp[j-1] : 0;
            dp[i] = 2 * dp[i-1] - dup;
            if(dp[i] < 0) dp[i] += mod;
            dp[i] %= mod;
            if(binary.charAt(i) == '0') lastZero = i;
            else lastOne = i;
        }
        
        int hasZero = 0;
        if(binary.contains("0")) hasZero = 1;
        
        
        return (int) (dp[binary.length()-1] + hasZero);
    }
}
