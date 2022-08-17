class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        h = stampHeight;
        w = stampWidth;
        init(grid);
        
		vector<vector<int>> diff(m+1, vector<int>(n+1, 0));  // 1-indexed
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (canStamp(i, j)) {
                    diff[i+1][j+1] ++;
                    diff[i+1][j+1-w] --;
                    diff[i+1-h][j+1] --;
                    diff[i+1-h][j+1-w] ++;
                }
            }
        }
        int cur = 0;
        for (int i = m-1; i >= 0; i--) {
            if (i < m-1) {
                for (int j = 0; j <= n; j++)
                    diff[i+1][j] += diff[i+2][j];
            }
            for (int j = n-1; j >= 0; j--) {
                cur += diff[i+1][j+1];
                if (cur > 0) {
                    grid[i][j] = 1;
                }
            }
            cur += diff[i+1][0];
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) return false;
            }
        }
        
        return true;
    }
private:
    vector<vector<int>> pre;
    int h;
    int w;
    int m;
    int n;
    void init(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        // initialize prefix sum
        pre.resize(m+1, vector<int>(n+1, 0));   // 1-indexed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + grid[i][j];
            }
        }
    }
    bool canStamp(int i, int j) {
        if (i+1 < h || j+1 < w) return false;
        return pre[i+1][j+1] - pre[i+1][j+1-w] - pre[i+1-h][j+1] + pre[i+1-h][j+1-w] == 0;
    }
};
