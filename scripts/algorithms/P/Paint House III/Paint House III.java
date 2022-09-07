// Runtime: 70 ms (Top 34.94%) | Memory: 52.8 MB (Top 34.74%)
class Solution {
    public int helper(int idx, int[] houses, int[][] cost,int target, int prevColor,int neigh,Integer[][][] dp)
    {
        if(idx==houses.length || neigh>target)
        {
            if(neigh==target)
                return 0;
            return Integer.MAX_VALUE;
        }
        if(dp[idx][prevColor][neigh]!=null)
            return dp[idx][prevColor][neigh];
        int minCost = Integer.MAX_VALUE;

        if(houses[idx]==0)
        {
            for(int j = 0;j<cost[idx].length;j++)
            {
                int minCostHere = Integer.MAX_VALUE;

                if(j+1==prevColor) // Painting the house with the same colour as that of the previous one.
                    minCostHere = helper(idx+1,houses,cost,target,prevColor,neigh,dp);

                else // Painting the house with a different color and incrementing the neighbour count.
                    minCostHere = helper(idx+1,houses,cost,target,j+1,neigh+1,dp);

                if(minCostHere!=Integer.MAX_VALUE)
                    minCostHere+=cost[idx][j];

                minCost = Math.min(minCostHere,minCost);
            }
        }
        else
        {
            if(houses[idx]==prevColor)
                minCost = helper(idx+1,houses,cost,target,prevColor,neigh,dp);
            else
                minCost = helper(idx+1,houses,cost,target,houses[idx],neigh+1,dp);
        }

        return dp[idx][prevColor][neigh] = minCost;

    }
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {

        Integer[][][] dp = new Integer[m][n+1][target+1];
        int ans = helper(0,houses,cost,target,0,0,dp);
        return ans==Integer.MAX_VALUE?-1:ans;
    }
}