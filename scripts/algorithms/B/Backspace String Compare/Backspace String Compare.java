// Runtime: 1 ms (Top 94.73%) | Memory: 42.2 MB (Top 59.43%)

class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1, j = t.length() - 1;
        while(i >= 0 || j >= 0) {
            i = getCurPos(i, s);
            j = getCurPos(j, t);
            if (i >= 0 && j >= 0 && s.charAt(i) != t.charAt(j)) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--;
            j--;
        }
        return true;
    }
    private int getCurPos(int i, String s) {
        int dels = 0;
        while( i >= 0) {
            if (s.charAt(i) == '#') {
                dels++;
                i--;
            } else if (dels > 0) {
                dels--;
                i--;
            } else break;
        }
        return i;
    }
}