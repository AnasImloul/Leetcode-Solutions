class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<int> g[100005];
        int n = vals.size();
        for(auto x: edges) {            
            if(vals[x[1]] > 0) g[x[0]].push_back(vals[x[1]]);
            if(vals[x[0]] > 0) g[x[1]].push_back(vals[x[0]]);
        }
        for(int i=0; i<n; i++) {
            sort(g[i].rbegin(), g[i].rend());
            for(int j=1; j<g[i].size(); j++) g[i][j] += g[i][j-1];
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            int cnt = vals[i];
            if(k and g[i].size()) {
                if(k <= g[i].size()) cnt += g[i][k-1];
                else cnt += g[i].back();
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};