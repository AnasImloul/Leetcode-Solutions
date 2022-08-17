class Solution {
public:
    typedef long long ll;
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<ll> pre_sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i-1]+candiesCount[i-1];
        }
        vector<bool> res(queries.size(), 0);
        
        for (int i = 0; i < queries.size(); ++i) {
            auto &p = queries[i];
            ll max = pre_sum[p[0]+1]-1;
            ll min = pre_sum[p[0]] / p[2];
            if (p[1] >= min && p[1] <= max)
                res[i] = true;
        }
        
        return res;
    }
};
