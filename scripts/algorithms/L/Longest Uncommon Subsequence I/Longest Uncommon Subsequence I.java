// Runtime: 0 ms (Top 100.00%) | Memory: 41.7 MB (Top 58.87%)
class Solution {
    public int findLUSlength(String a, String b) {
        if(a.equals(b)) return -1;
        return Math.max(a.length(),b.length());
    }
}