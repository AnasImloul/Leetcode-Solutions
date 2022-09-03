// Runtime: 0 ms (Top 100.00%) | Memory: 42.5 MB (Top 17.04%)
class Solution {
    public boolean rotateString(String s, String goal) {
        int n = s.length(), m = goal.length();
        if (m != n) return false;

        for (int offset = 0; offset < n; offset++) {
            if (isMatch(s, goal, offset)) return true;
        }
        return false;
    }

    private boolean isMatch(String s, String g, int offset) {
        int n = s.length();
        for (int si = 0; si < n; si++) {
            int gi = (si + offset) % n;
            if (s.charAt(si) != g.charAt(gi)) return false;
        }
        return true;
    }
}