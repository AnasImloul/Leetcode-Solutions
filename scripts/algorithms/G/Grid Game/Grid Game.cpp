// Runtime: 492 ms (Top 5.15%) | Memory: 71.1 MB (Top 28.62%)
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> pre1(n+1,0);
        vector<long long> pre2(n+1,0);
        long long s=0, ans=0;
        grid[0][0]=0; grid[1][n-1]=0; // Picked by First Robot
        for(int i=0;i<n;i++){
            pre1[i+1]=pre1[i]+grid[0][i];
            pre2[i+1]=pre2[i]+grid[1][i];
            s+=grid[0][i];
        }
        for(int i=1;i<=n;i++){
            ans=max(min(s-pre1[i],pre2[i]),ans);
        }
        return ans;
    }
};