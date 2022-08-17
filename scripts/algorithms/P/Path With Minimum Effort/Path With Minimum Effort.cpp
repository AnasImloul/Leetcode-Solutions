class Solution {
public:
    bool isValid(vector<vector<int>>& h, int x, int y) {
        return x < n and x >= 0 and y < m and y >= 0;
    }
	
    bool recDFS(vector<vector<int>>& h, int k, int x, int y) {
        visited[x][y] = true;
        if (x == n-1 && y == m-1)
            return true;
            
        for (int i = 0; i < 4; i++) {
            int x_curr = x + x_points[i];
            int y_curr = y + y_points[i];
            if (isValid(h, x_curr, y_curr) && !visited[x_curr][y_curr] && abs(h[x_curr][y_curr] - h[x][y]) <= k)
                if (recDFS(h, k, x_curr, y_curr)) return true;
        }

        return false;
    }
    
    bool possibleLessEqK(vector<vector<int>>& h, int k) {
        visited.assign(n,vector<bool> (m, false));
        return recDFS(h, k, 0, 0);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        int lo = 0, hi = 1e6, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (possibleLessEqK(heights, mid))
                hi = mid;
            else 
                lo = mid + 1;
        }
        
        return lo;
    }
    
private:
    vector<vector<bool>> visited;
    vector<int> x_points = {1, 0, -1, 0};
    vector<int> y_points = {0, 1, 0, -1};
    int n;
    int m;
};
