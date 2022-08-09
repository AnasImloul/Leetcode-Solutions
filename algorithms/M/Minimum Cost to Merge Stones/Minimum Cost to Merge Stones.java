class Solution {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        int[] prefixSums = new int[n];
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += stones[i];
            prefixSums[i] = sum;
        }
        Integer[][] dp = new Integer[n][n];
        return merge(0, n-1, stones, k, dp, prefixSums);
    }
    
    private int merge(int start, int end, int[] stones, int k, Integer[][] dp, int[] prefixSums) {
        if (dp[start][end] != null) {
            // already computed
            return dp[start][end];
        }
        if (start == end) {
            // base case: single pile already
            dp[start][end] = 0;
            return 0;
        }
        if ((end - start) % (k-1) != 0) {
            // end - start + 1 is how many piles to merge
            // so end - start is how many piles we have to delete by merge
            // and at each merge, we delete k-1 piles.
            dp[start][end] = -1;
            return -1;
        }
        // ok so now have K or more piles to merge
        // need to test all possible K-paritions using K-1 delimiters and recurse on them and min.
        AtomicInteger minCostWrapper = new AtomicInteger(Integer.MAX_VALUE);
        partition(start, end, stones, k, 0, k - 1, minCostWrapper, dp, prefixSums);
        int min = minCostWrapper.get();
        int rtn = min == Integer.MAX_VALUE? -1 : min;
        rtn += prefixSums[end] - (start - 1 >=0 ? prefixSums[start-1] : 0);
        dp[start][end] = rtn;
        return rtn;
    }
    
    private void partition(int curr, 
                          int end,
                          int[] stones,
                          int k,
                          int costSoFar, 
                          int delimiters,
                          AtomicInteger minCost, 
                          Integer[][] dp, 
                           int[] prefixSums) {
        if (delimiters == 0) {
            // base case: no more delimiters
            int cost = merge(curr, end, stones, k, dp, prefixSums);
            cost += costSoFar;
            if (cost != -1 && cost < minCost.get()) {
                minCost.set(cost);
            }
            return;
        }
        //for(int i=curr; i<end && (end - i - 1) >= delimiters - 1)
        for(int i=curr; (i<end) && (end - i) >= delimiters; i++) {
            int nextCost = merge(curr, i, stones, k, dp, prefixSums);
            if (nextCost != -1) {
                partition(i+1, end, stones, k, costSoFar + nextCost, delimiters - 1, minCost, dp, prefixSums);
            }
        }
    }
}
