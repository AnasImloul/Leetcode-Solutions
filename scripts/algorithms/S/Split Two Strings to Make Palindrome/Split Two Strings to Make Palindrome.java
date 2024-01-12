// Runtime: 3 ms (Top 100.0%) | Memory: 45.60 MB (Top 14.69%)

class Solution {
    public boolean checkPalindromeFormation(String a, String b) {
        // either way of split should give us a palindrome
        return cut(a, b) || cut(b, a);
    }

    // method to match letters from both ends
    private boolean cut(String a, String b) {
        int i = 0, j = a.length() - 1;
        // converge from both ends till we have same letters
        while (i < j && a.charAt(i) == b.charAt(j)) {
            i++; j--;
        }

        // the case when we surpassed the mid point from both ends
        if (i >= j) return true;
        // the case when there is still a substring left in between
        // or say we didn't reach the mid point
        // we will check if that substring is a palindrome or not
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    // method to check if a string is palindrome
    private boolean isPalindrome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }

        return true;
    }
}
