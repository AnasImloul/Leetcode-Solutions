// Runtime: 77 ms (Top 37.5%) | Memory: 48.02 MB (Top 54.6%)

/*
Solution:

1. Use two pointers, one initialised to 0 and the other initialised to end of string. Check if characters at each index
are the same. If they are the same, shrink both pointers. Else, we have two possibilities: one that neglects character
at left pointer and the other that neglects character at right pointer. Hence, we check if s[low+1...right] is a palindrome
or s[low...right-1] is a palindrome. If one of them is a palindrome, we know that we can form a palindrome with one deletion and return true. Else, we require more than one deletion, and hence we return false.
*/
var validPalindrome = function(s) {
    let low = 0, high = s.length-1;
    while (low < high) {
        if (s[low] !== s[high]) {
            return isPalindrome(s, low+1, high) || isPalindrome(s, low, high-1);
        }
        low++, high--;
    }
    return true;
    // T.C: O(N)
    // S.C: O(1)
};

function isPalindrome(str, low, high) {
    while (low < high) {
        if (str[low] !== str[high]) return false;
        low++, high--;
    }
    return true;
}