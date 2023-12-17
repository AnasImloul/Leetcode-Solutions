// Runtime: 4 ms (Top 59.22%) | Memory: 55.50 MB (Top 5.02%)

class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {        
        if (original.length != m * n) return new int[0][];
        
        int[][] ans = new int[m][n];
        int currRow = 0, currCol = 0;
        
        for (int num : original) {
            ans[currRow][currCol++] = num;
            
            if (currCol == n) {
                currCol = 0;
                currRow++;
            }
        }
        
        return ans;
    }
}

// TC: O(n), SC: O(m * n)
