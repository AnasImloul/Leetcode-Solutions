// Runtime: 145 ms (Top 80.13%) | Memory: 84.00 MB (Top 13.41%)

#pragma GCC optimize("O3")
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        for(int i=1;  i<m; i++){
            #pragma unroll
            for(int j=0; j<n; j++){
                if (matrix[i][j]!=0)
                    matrix[i][j]+=matrix[i-1][j];
            }
            auto row=matrix[i];
            sort(row.begin(), row.end());
            #pragma unroll
            for(int i=0; i<n; i++)
                area=max(area, row[i]*(n-1-i+1));
        }
        return area;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
