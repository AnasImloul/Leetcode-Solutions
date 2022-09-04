// Runtime: 17 ms (Top 24.85%) | Memory: 54.4 MB (Top 36.19%)
class Solution {
    public int minPartitions(String n) {
        int res = 0;
        for (int i = 0; i < n.length(); i++) {
            res = Math.max(res, n.charAt(i) - '0');
        }
        return res;
    }
}