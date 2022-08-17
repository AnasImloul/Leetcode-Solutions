class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /* Minimize cost of steps, where you can take one or two steps.
           
           At each step, store the minimum of the current step plus the step previous
           or the step two previous. At the last step we can either take the last
           element or leave it off.
        */
        int n = cost.size();
        for(int i = 2; i < n; i++) {
            cost[i] = min(cost[i] + cost[i-2], cost[i] + cost[i-1]);    
        }
        
        return min(cost[n-1], cost[n-2]);
    }
};
