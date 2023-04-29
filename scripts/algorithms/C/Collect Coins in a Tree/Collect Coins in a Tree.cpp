class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        vector<vector<int>> E(coins.size());
        for (auto &e : edges) 
            E[e[0]].push_back(e[1]), E[e[1]].push_back(e[0]);
        vector<int> dis(coins.size(), -1), dp(coins.size(), 0), hasDis2(coins.size(), 0), hasDis1(coins.size(), 0);
        function<void(int, int)> dfs = [&] (int u, int fa) {
            if (coins[u]) dis[u] = 0;
            for (auto &v : E[u]) {
                if (v == fa) continue;
                dfs(v, u);
                if (~dis[v]) {
                    dis[u] = max(dis[u], dis[v] + 1);
                    hasDis1[u]++;
                    if (dis[v] > 1) dp[u] += dp[v] + 2;
                    if (dis[v] >= 1) hasDis2[u]++;
                }
            }
        };
        dfs(0, -1);
        int ans = dp[0];
        function<void(int, int)> dfs2 = [&] (int u, int fa) {
            if (dis[u] == -1) return;
            for (auto &v : E[u]) {
                if (v == fa) continue;
                int tmpAns = dp[u];
                if (dis[v] <= 1) tmpAns += 2;
                if (hasDis2[u] == 0 || hasDis2[u] == 1 && dis[v] >= 1) tmpAns -= 2;
                dp[v] = tmpAns;
                ans = min(dp[v], ans);
                hasDis1[v] += min(1, coins[u] + hasDis1[u] - (dis[v] >= 0) + hasDis2[u] - (dis[v] >= 1));
                hasDis2[v] += min(1, hasDis1[u] - (dis[v] >= 0) + hasDis2[u] - (dis[v] >= 1));
                dfs2(v, u);
            }
        };
        dfs2(0, -1);
        return ans;
    }
};