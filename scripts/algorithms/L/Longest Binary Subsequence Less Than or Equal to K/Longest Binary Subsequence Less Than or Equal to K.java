class Solution {
    public int longestSubsequence(String s, int k) {
        int numOfZeros = 0;
        int numOfOnes = 0;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(ch == '0'){
                numOfZeros++;
            }
        }
        int sum = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            char ch = s.charAt(i);
            if(ch == '1'){
                double val = Math.pow(2, s.length() - i - 1);
                sum += val;
                if(sum <= k){
                    numOfOnes++;
                }
            }
        }
        return numOfZeros + numOfOnes;
    }
}