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
