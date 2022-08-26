// Runtime: 101 ms (Top 5.28%) | Memory: 41.3 MB (Top 24.12%)
class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long ways = 0;
        long penscost = 0;
        while(penscost <= total) {
            long remainingAmount = total - penscost;
            long pencils = remainingAmount/cost2 + 1;
            ways += pencils;
            penscost += cost1;
        }
        return ways;
    }
}