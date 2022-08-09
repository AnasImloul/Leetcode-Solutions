class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int a[] = new int[cost.length+1];
        a[0]=0;
        a[1]=0;
        
        for(int i=2;i<=cost.length;i++)
        {
            a[i]= Math.min(cost[i-1]+a[i-1], cost[i-2]+a[i-2]);
        }
        return a[cost.length];
    }
}
