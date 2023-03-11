class Solution {
    public String firstPalindrome(String[] words) {
        for (String s : words) {
            StringBuilder sb = new StringBuilder(s);
            if (s.equals(sb.reverse().toString())) {
                return s;
            }
        }
        return "";
    }
}