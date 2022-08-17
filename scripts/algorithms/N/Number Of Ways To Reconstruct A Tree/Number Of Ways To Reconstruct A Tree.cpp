class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (int i = 0; i < pairs.size(); i++) {
            adj[pairs[i][0]].emplace(pairs[i][1]);
            adj[pairs[i][1]].emplace(pairs[i][0]);
        }
        
        priority_queue<pair<int, int>> q;
        for (auto& [x, arr] : adj) {
            q.push({arr.size(), x});
        }
        
        int n = q.size();
        bool multiple = false;
        unordered_set<int> seen;
        while (!q.empty()) {
            auto [sz, v] = q.top();
            q.pop();
            
            int u = 0;
            int usz = n + 1;
            if (!seen.empty()) {
                for (auto x : adj[v]) {
                    if (adj[x].size() < usz && seen.count(x)) {
                        u = x;
                        usz = adj[x].size();
                    }
                }
            }
            
            seen.emplace(v);
            if (u == 0) {
                if (sz != (n - 1)) {
                    return 0;
                }
                continue;
            }
            
            
            for (auto x : adj[v]) {
                if (x == u) {
                    continue;
                }
                
                if (!adj[u].count(x)) {
                    return 0;
                }
            }
            
            if (usz == sz) {
                multiple = true;
            }
        }
        
        if (multiple) {
            return 2;
        }
        
        return 1;
    }
};
