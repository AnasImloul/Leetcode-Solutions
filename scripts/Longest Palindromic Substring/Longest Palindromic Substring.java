class Solution {
    String max = "";
    
    private void checkPalindrome(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            if (r - l >= max.length()) {
                max = s.substring(l, r + 1);
            }   

            l--;
            r++;
        }
    }
    
    public String longestPalindrome(String s) {
        for (int i = 0; i < s.length(); i++) {
            checkPalindrome(s, i, i);
            checkPalindrome(s, i, i + 1);   
        }
        
        return max;
    }
}
