class Solution {
    public boolean checkPalindromeFormation(String a, String b) {
        return split(a, b) || split(b, a);
    }
    
    private boolean split(String a, String b) {
        int left = 0, right = a.length() - 1;
        while (left < right && a.charAt(left) == b.charAt(right)) {
            left++;
            right--;
        }
        if (left >= right) return true;
        return isPalindrome(a, left, right) || isPalindrome(b, left, right);
    }
    
    private boolean isPalindrome(String s, int left, int right) {
        while (left <= right) {
            if (s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
}
