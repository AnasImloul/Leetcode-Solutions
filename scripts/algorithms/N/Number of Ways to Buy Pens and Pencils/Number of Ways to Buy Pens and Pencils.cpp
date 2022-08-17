class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        long long penscost = 0;
        while(penscost <= total) {
            long long remainingAmount = total - penscost;
            long long pencils = remainingAmount/cost2 + 1;
            ways += pencils;
            penscost += cost1;
        }
        return ways;
    }
};
