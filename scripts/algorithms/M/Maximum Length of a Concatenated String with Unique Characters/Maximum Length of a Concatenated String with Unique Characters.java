// Runtime: 32 ms (Top 61.57%) | Memory: 49.1 MB (Top 67.72%)
class Solution {
    public int maxLength(List<String> arr) {
        String[] words = arr.stream().filter(o -> o.chars().distinct().count() == o.length()).toArray(String[]::new);
        int[] dp = new int[1<<words.length];
        int[] ok = new int[1<<words.length];
        for (int i = 0; i < words.length; i++){
            for (char ch : words[i].toCharArray()){
                ok[1<<i]|=1<<(ch-'a');
                dp[1<<i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < dp.length; i++){
            if ((ok[i&(i-1)]&ok[i&-i])==0){
                dp[i] = dp[i&(i-1)] + dp[i&-i];
                ok[i] = ok[i&(i-1)] | ok[i&-i];
            }
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}