// Runtime: 670 ms (Top 16.39%) | Memory: 64.9 MB (Top 74.39%)
typedef long long ll;

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll, ll> gcdCount;
        ll ans = 0;
        for (ll i = 0; i < nums.size(); ++i)
        {
            ll currgcd = __gcd(nums[i], k);
            for (auto &[gc_d, count] : gcdCount)
                if ((currgcd * gc_d) % k == 0)
                    ans += count;
            gcdCount[currgcd]++;
        }
        return ans;
    }
};