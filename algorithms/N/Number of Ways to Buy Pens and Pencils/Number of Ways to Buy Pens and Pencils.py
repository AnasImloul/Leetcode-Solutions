class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        ways = 0;
        penscost = 0;
        while penscost <= total:
            remainingAmount = total - penscost;
            pencils = remainingAmount//cost2 + 1;
            ways += pencils;
            penscost += cost1;
        return ways
