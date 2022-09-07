// Runtime: 1 ms (Top 99.91%) | Memory: 54.3 MB (Top 74.13%)
class Solution {
    public void reverseString(char[] s) {
        int start = 0, end = s.length-1;

        while(start < end) {
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
            start++;
            end--;
        }

    }
}