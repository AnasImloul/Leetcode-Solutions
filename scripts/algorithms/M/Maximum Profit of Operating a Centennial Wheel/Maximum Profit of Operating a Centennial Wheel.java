class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        int maxProfit = 0, shift = -1, waiting = 0, profit = 0;
        for(int i = 0; i < customers.length; i++) {
            waiting += customers[i]; // In each shift adding new passenger to the waiting line
            profit += Math.min(waiting, 4) * boardingCost - runningCost;
            if(profit > maxProfit) {
                shift = i + 1;
                maxProfit = profit;
            }
            waiting = Math.max(waiting - 4, 0);
        }
        if(boardingCost * 4 > runningCost) { // profitable to serve all the remaining waiting line?
            shift += waiting / 4;
            shift += waiting % 4 * boardingCost - runningCost > 0 ? 1:0; // profitable for the last round?
        }
        return shift;
    }
}
