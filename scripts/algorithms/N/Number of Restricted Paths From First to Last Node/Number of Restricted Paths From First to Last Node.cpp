// Runtime: 1369 ms (Top 10.94%) | Memory: 161.8 MB (Top 51.63%)
typedef pair<int, int> pii;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> gp;
        for (auto& edge : edges) {
            gp[edge[0]].push_back({edge[1], edge[2]});
            gp[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({0, n});
        dist[n] = 0;

        int u, v, w;
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            u = p.second;
            for (auto& to : gp[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<int> dp(n + 1, -1);
        return dfs(gp, n, dp, dist);
    }

    int dfs(unordered_map<int, vector<pair<int, int>>>& gp, int s, vector<int>& dp, vector<int>& dist) {
        int mod = 1e9+7;
        if (s == 1) return 1;
        if (dp[s] != -1) return dp[s];
        int sum = 0, weight, val;
        for (auto& n : gp[s]) {
            weight = dist[s];
            val = dist[n.first];
            if (val > weight) {
                sum = (sum % mod + dfs(gp, n.first, dp, dist) % mod) % mod;
            }
        }
        return dp[s] = sum % mod;
    }
};