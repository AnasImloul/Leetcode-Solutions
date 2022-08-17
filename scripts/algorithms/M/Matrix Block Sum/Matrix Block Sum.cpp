class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<int>>grid(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int minus=(i-1>=0 && j-1>=0)?grid[i-1][j-1]:0;
                int add1=(i-1>=0)?grid[i-1][j]:0;
                int add2=(j-1>=0)?grid[i][j-1]:0;
                grid[i][j]=mat[i][j]+add1+add2-minus;
            }
        }
        
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxRow=min(i+k,n-1),maxCol=min(j+k,m-1);
                int base=grid[maxRow][maxCol];
                base-=(i-k-1>=0)?grid[i-k-1][maxCol]:0;
                base-=(j-k-1>=0)?grid[maxRow][j-k-1]:0;
                base+=(i-k-1>=0 && j-k-1>=0)?grid[i-k-1][j-k-1]:0;
                ans[i][j]=base;
            }
        }
        
        return ans;
    }
};
