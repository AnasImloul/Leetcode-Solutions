class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length, ans = 0, cur = 0;
        for (int k = 0; k < n - 1; k++){ // looking for the fitting row for row k
            for (int i = k; i < n; i++){ // start from row k looking downward
                for (int j = k + 1; j < n; j++){ // all cell after and at k + 1 must be 0
                    if (grid[i][j] == 1)
                        break;
                    if (j < n - 1)
                        continue;
                    for (int m = i; m > k; m--){ // j == n - 1 here, so we found a valid row
                        int[] tmp = grid[m - 1];  // swap it into the correct row - row k
                        grid[m - 1] = grid[m];
                        grid[m] = tmp;
                        ans++;
                    }
                    i = n;
                }
                if (i == n - 1) // i reaches the end and did not find a fitting row, return -1
                    return -1;
            }
        }
        return ans;
    }
}
