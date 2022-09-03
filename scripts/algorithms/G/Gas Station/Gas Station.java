// Runtime: 1 ms (Top 100.00%) | Memory: 62.5 MB (Top 91.09%)
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
       // *Upvote will be appreciated*
        int totalFuel = 0;
        int totalCost = 0;
        int n = gas.length;
        for(int i = 0; i < n; i++) {
            totalFuel += gas[i];
        }
        for(int i = 0; i < n; i++) {
            totalCost += cost[i];
        }
        // if totalfuel < totalCost then It is not possible to tavel
        if(totalFuel < totalCost) {
            return -1;
        }

        // It is greather then There may be an Answer
        int start = 0;
        int currFuel = 0;
        for(int i = 0; i < n; i++) {
            currFuel += (gas[i]-cost[i]);
            if(currFuel < 0) { // It Current Fuel is less than 0 mean we can't star from that index
                start = i+1; // so we start from next index
                currFuel = 0;
            }
        }
        return start;
    }
}