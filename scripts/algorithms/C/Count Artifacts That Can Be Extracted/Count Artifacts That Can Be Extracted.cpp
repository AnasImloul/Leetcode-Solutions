class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>>arr(n,vector<int>(n,1));
        for(vector<int>& v : dig){
            arr[v[0]][v[1]] = 0;
        }
        int preSum[n+1][n+1];
        for(int i=0;i<=n;i++){preSum[i][0] = 0; preSum[0][i] = 0;}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + arr[i-1][j-1];
            }
        }
        int res = 0,sum,r1,c1,r2,c2;
        for(vector<int>& v : artifacts){
            r1 = v[0]; c1 = v[1]; r2 = v[2]; c2 = v[3];
            sum = preSum[r2+1][c2+1] - preSum[r1][c2+1] - preSum[r2+1][c1] + preSum[r1][c1];
            if(sum == 0){res++;}
        }
        return res;
    }
};
