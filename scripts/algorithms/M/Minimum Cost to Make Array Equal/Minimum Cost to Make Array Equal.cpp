// Runtime: 61 ms (Top 89.25%) | Memory: 43.20 MB (Top 30.22%)

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long ans = 1e18;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < nums.size(); i++)
            v[i] = {nums[i], cost[i]};
        
        sort(v.begin(), v.end());
        vector<long long> pref(n), suff(n);
        long long c_sum = 0, nc = 0;
        for(int i = 0; i < n; i++){
            pref[i] = (v[i].first * c_sum - nc);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        c_sum = 0, nc = 0;
        for(int i = n - 1; i >= 0; i--){
            ans = min(ans, abs(v[i].first * c_sum - nc) + pref[i]);
            c_sum += (long long)v[i].second;
            nc += (long long)v[i].first * (long long)v[i].second;
        }
        return ans;
    }
};
