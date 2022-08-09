class Solution {
    public int balancedStringSplit(String s) {
        int nl = 0;
        int nr = 0;
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.substring(i,i+1).equals("L")) ++nl;
            else ++nr;
            if (nr == nl) {
                ++count;
            }
        }
        return count;
    }
}
