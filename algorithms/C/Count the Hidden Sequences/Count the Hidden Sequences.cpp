using ll = long long int;
class Solution {
    public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<ll> ans; 
        ans.push_back(lower); 
        ll mn = lower;
        ll mx = lower;
        for (const auto& d: differences) {
            ans.push_back(d + ans.back());
            mn = min(mn, ans.back());
            mx = max(mx, ans.back());
        }

        ll add = lower - mn;
        
        for (auto& i: ans) i += add;
        for (auto& i: ans) if (i < lower or upper < i) return 0;
        
        ll add2 = upper - mx;
        
        return add2 - add + 1;
    }
}; 
