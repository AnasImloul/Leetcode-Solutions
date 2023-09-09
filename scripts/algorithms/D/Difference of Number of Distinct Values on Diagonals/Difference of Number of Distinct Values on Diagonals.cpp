// Runtime: 55 ms (Top 92.1%) | Memory: 34.72 MB (Top 90.3%)

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        int i,j,a,b,k;
        for(k = 0; k < n; k++){
            unordered_map<int,int> mp1,mp2;
            i = 0, j = k;
            while(j<n&&i<m){
                mp1[grid[i][j]]++;
                i++;j++;
            }
            i = 0, j = k;
            while(i<m&&j<n){
                mp1[grid[i][j]]--;
                if(mp1[grid[i][j]]==0){
                    mp1.erase(grid[i][j]);
                }
                a = mp1.size(),b = mp2.size();
                ans[i][j] = abs(a-b);
                mp2[grid[i][j]]++;
                i++;j++;
            }
        }
        for(k = 1; k < m; k++){
            unordered_map<int,int> mp1,mp2;
            j = 0, i = k;
            while(j<n&&i<m){
                mp1[grid[i][j]]++;
                i++;j++;
            }
            j = 0, i = k;
            while(i<m&&j<n){
                mp1[grid[i][j]]--;
                if(mp1[grid[i][j]]==0){
                    mp1.erase(grid[i][j]);
                }
                a = mp1.size(),b = mp2.size();
                ans[i][j] = abs(a-b);
                mp2[grid[i][j]]++;
                i++;j++;
            }
        }
        return ans;
    }
};