#define sz(x) static_cast<int32_t>(x.size())
template <class T> inline void chmax(T &x,T y){ x = max((x), (y));}

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector <vector<int>> g(n);
        for (auto it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end(), [&](const auto a1, const auto a2) {
                return scores[a1] > scores[a2];
            });
        }
        int ans = -1;
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i < sz(g[u]) and j < sz(g[v]) and g[u][i] != g[v][j] and u != g[v][j] and v != g[u][i]) {
                        chmax(ans, scores[u] + scores[v] + scores[g[u][i]] + scores[g[v][j]]);
                    }
                }
            }
        }
        return ans;
    }
};
