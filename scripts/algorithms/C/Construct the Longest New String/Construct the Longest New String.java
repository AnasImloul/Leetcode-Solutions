// Runtime: 1 ms (Top 100.0%) | Memory: 41.20 MB (Top 53.45%)

class Solution {
    public int longestString(int x, int y, int z) {
        int mn = Math.min(x, y);
        if (x == y) {
            return (4 * x + 2 * z);
        } 
        else {
            return (2 * mn + (mn + 1) * 2 + 2 * z);
        }
    }
}
