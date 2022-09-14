// Runtime: 607 ms (Top 6.76%) | Memory: 113.6 MB (Top 19.34%)
class Solution {
public:
    vector<vector<int>> nbrs = {{0,1},{1,0},{-1,0},{0,-1}};
    pair<int, int> dfs(vector<vector<int>> &land, int i, int j, vector<vector<bool>> &visited) {
        visited[i][j] = true;
        pair<int, int> res = make_pair(i, j);
        for(auto &nbr: nbrs) {
            int x = i + nbr[0];
            int y = j + nbr[1];
            if(x < 0 || y < 0 || x >= land.size() || y >= land[0].size() || visited[x][y] || land[x][y] != 1)
                continue;
            pair<int, int> ans = dfs(land, x, y, visited);
            res.first = max(res.first, ans.first);
            res.second = max(res.second, ans.second);
        }
        return res;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && land[i][j] == 1) {
                    pair<int, int> p = dfs(land, i, j, visited);
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(j);
                    res.push_back(p.first);
                    res.push_back(p.second);
                    ans.push_back(res);
                    cout << 1 << endl;
                }
            }
        }
        return ans;
    }
};