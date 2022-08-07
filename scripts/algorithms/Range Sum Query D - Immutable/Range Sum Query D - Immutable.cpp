//Using row prefix sum O(m)
class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i<m;i++){
            vector<int> row(n);
            row[0] = matrix[i][0];
            for(int j = 1;j<n;j++){
                row[j] = row[j-1] + matrix[i][j];
            }
            prefix.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1;i<=row2;i++){
            sum += prefix[i][col2];
            if(col1>0) sum -= prefix[i][col1-1];
        }
        return sum;
    }
};

//Using mat prefix sum O(1)
class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix = vector<vector<int>>(m+1,vector<int>(n+1,0));
        prefix[1][1] = matrix[0][0];
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + matrix[i-1][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum += prefix[row2+1][col2+1];
        sum -= prefix[row1][col2+1];
        sum -= prefix[row2+1][col1];
        sum += prefix[row1][col1];
        return sum;
    }
};
