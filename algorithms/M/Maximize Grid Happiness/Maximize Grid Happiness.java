class Solution {
    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        // introvert = -1, extrovert = 1
        return dfs(m, n, 0, introvertsCount, extrovertsCount, 0, 0, new Integer[m+1][introvertsCount+1][extrovertsCount+1][(1 << (n+1))][(1 << (n+1))]);
    }
    public int dfs(int m, int n, int row, int in_count, int ex_count, int prev_in_pos, int prev_ex_pos, Integer[][][][][] dp) {
        if(dp[row][in_count][ex_count][prev_in_pos][prev_ex_pos] != null)
            return dp[row][in_count][ex_count][prev_in_pos][prev_ex_pos];
        if((in_count == 0 && ex_count == 0) || (row == m)) 
            return 0;
        List<int[]> possible_permutations = new ArrayList<int[]>();  // get all possible ways to fill a row**** with given number of introverts & extroverts
        int[] aux = new int[n];
        getPermutations(in_count, ex_count, aux, 0, possible_permutations, n);
        
        int ans = 0;
        for(int[] possible : possible_permutations) {
            int curr_in_count = in_count, curr_ex_count = ex_count;
            int curr_in_pos = 0, curr_ex_pos = 0;
            for(int i = 0; i < n; i++) {
                if(possible[i] == 0)
                    continue;
                if(possible[i] == -1) {
                    curr_in_count--;
                    curr_in_pos |= (1 << i);
                }
                else {
                    curr_ex_count--;
                    curr_ex_pos |= (1 << i);
                }
            }
            int curr_row_val = calculate(possible, prev_in_pos, prev_ex_pos, n);            
            int rest_rows_val = dfs(m, n, row+1, curr_in_count, curr_ex_count, curr_in_pos, curr_ex_pos, dp);
            ans = Math.max(ans, curr_row_val + rest_rows_val);
        }
        return dp[row][in_count][ex_count][prev_in_pos][prev_ex_pos] = ans;
    }
    // for each row, find happiness (keeping in account : left, right and upper neighors, for people in this row) and
    //                              (keeping in account : lower neighbors for people in previous row)
    public int calculate(int[] currRow, int prev_in_pos, int prev_ex_pos, int columns) {
         int res = 0;
         // vertical neighbors
         for(int i = 0; i < columns; i++) {
             if(currRow[i] == 0)                                continue;
             if(currRow[i] == 1) {
                 res += 40;
                 if( (prev_in_pos & (1 << i)) != 0)             res += (20 - 30);       // -30 : because previous upper neighbor is introvert
                 else if( (prev_ex_pos & (1 << i)) != 0 )       res += (20 + 20);
             }
             else {
                 res += 120;
                 if( (prev_in_pos & (1 << i)) != 0)             res += (-30 - 30);
                 else if( (prev_ex_pos & (1 << i)) != 0 )       res += (-30 + 20);
             }
         }
         // horizontal neighbors
         for(int i = 0; i < columns; i++) {
             if(currRow[i] == 0)                                continue;
             if(currRow[i] == -1) {
                 if(i-1 >= 0 && currRow[i-1] != 0)              res += (-30);
                 if(i+1 < columns && currRow[i+1] != 0)         res += (-30);
             }
             else {
                 if(i-1 >= 0 && currRow[i-1] != 0)              res += (20);
                 if(i+1 < columns && currRow[i+1] != 0)         res += (20);
             }
         }
         return res;
    }
    public void getPermutations(int in_count, int ex_count, int[] curr, int index, List<int[]> possible_permutations, int len) {
        if((in_count == 0 && ex_count == 0) || index == len) {
            int[] arr = new int[len];
            for(int i = 0; i < len; i++)
                arr[i] = curr[i];
            possible_permutations.add(arr);
            return;
        }
        if(in_count > 0) {
            curr[index] = -1;
            getPermutations(in_count-1, ex_count, curr, index+1, possible_permutations, len);
            curr[index] = 0;
        }
        if(ex_count > 0) {
            curr[index] = 1;
            getPermutations(in_count, ex_count-1, curr, index+1, possible_permutations, len);
            curr[index] = 0;
        }
        getPermutations(in_count, ex_count, curr, index+1, possible_permutations, len);
    }
}
