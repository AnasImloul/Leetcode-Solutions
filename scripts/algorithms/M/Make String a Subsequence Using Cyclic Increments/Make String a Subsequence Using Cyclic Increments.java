// Runtime: 42 ms (Top 5.53%) | Memory: 72.70 MB (Top 5.53%)

class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        if(str2.length() > str1.length()) return false;
        return solve(0, 0, str1, str2, str1.length(), str2.length());
        
    }
    private boolean solve(int index1, int index2, String str1, String str2, int n, int m) {
        if(index2 == m) return true;
        if(index1== n) return false;
        boolean ans = false;
        if(
            str1.charAt(index1) == str2.charAt(index2) ||
            (((str1.charAt(index1)-'a' +1)%26) +'a') == str2.charAt(index2) 
        ) {
            ans |=solve(index1 +1, index2 +1, str1, str2, n, m);
        }
        else{
            ans |= solve(index1 +1, index2, str1, str2, n, m);
        }
        return ans;
    }
}
