class Solution {
    int[][] g;
    int[][] f;

    public int getMoneyAmount(int n) {
        g = new int[n + 1][n + 1];
        f = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(g[i], -1);
            Arrays.fill(f[i], -1);
        }
        return minMax(1, n, -1, true);
    }
    
    public int minMax(int start, int end, int picked, boolean isGussing) {
        if (start == end) {
            return 0;
        }
        if (isGussing) {
            if (f[start][end] != -1) {
                return f[start][end];
            }
            int minCost = Integer.MAX_VALUE;
            for (int i = start; i <= end; i++) {
                int tempCost = i + minMax(start, end, i, false);
                minCost = Math.min(minCost, tempCost);
            }
            f[start][end] = minCost;
            return minCost;
        } else {
            int tempCost2 = Integer.MIN_VALUE;
            int tempCost1 = Integer.MIN_VALUE;
            
            if (picked > start) {
                if (g[start][picked - 1] != -1) {
                    tempCost1 = g[start][picked - 1];
                } else {
                    tempCost1 = minMax(start, picked - 1, -1, true);
                    g[start][picked - 1] = tempCost1;
                }
            }
            
            if (picked < end) {
                if (g[picked + 1][end] != -1) {
                    tempCost2 = g[picked + 1][end];
                } else {
                    tempCost2 = minMax(picked + 1, end, -1, true);
                    g[picked + 1][end] = tempCost2;
                }
            }
            g[start][end] = Math.max(tempCost1, tempCost2);
            return g[start][end];
        }
    }
}
