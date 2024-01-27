// Runtime: 0 ms (Top 100.0%) | Memory: 58.70 MB (Top 6.47%)

class Solution {
    public int maximumGroups(int[] grades) {
        int len = grades.length;
        int groups = (int)(-1 + Math.sqrt(1 + 8*len))/2;
        return groups;
    }
}