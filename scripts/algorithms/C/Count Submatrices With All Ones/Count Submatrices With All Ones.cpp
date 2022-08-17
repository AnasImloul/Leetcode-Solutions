class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n,vector<int>(m+1,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v[i][j+1] = v[i][j] + mat[i][j];
            }
        }
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=i+1; j<=m; j++){
                int cnt = 0;
                for(int k=0; k<n; k++){
                    int x = v[k][j] - v[k][i];
                    if(x == (j-i)){
                        cnt++;
                    }else{
                        res += cnt*(cnt+1)/2;
                        cnt = 0;
                    }
                }
                res += cnt*(cnt+1)/2;
            }
        }
        return res;
    }
};
