// Runtime: 942 ms (Top 54.00%) | Memory: 221.2 MB (Top 27.50%)
class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();

        vector<long> fact(n + 1, 1), inv_fact(n + 1, 1), inv(n+1, 1);
        for (int i = 2; i <= n; ++i) {
            inv[i] = mod - mod / i * inv[mod % i] % mod;
            fact[i] = fact[i - 1] * i % mod;
            inv_fact[i] = inv_fact[i-1] * inv[i] % mod;
        }

        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[prevRoom[i]].push_back(i);
        }

        return postorder(children, fact, inv_fact, 0).first;
    }
private:
    long mod = 1e9 + 7;

    pair<long, long> postorder(const vector<vector<int>>& children, const vector<long>& fact, const vector<long>& inv_fact, int curr) {
        if(children[curr].size() == 0)
            return {1,1};
        long tot_ways = 1, my_size = 1;
        for(int child : children[curr]) {
            auto [ways, size_of] = postorder(children, fact, inv_fact, child);
            tot_ways = ((tot_ways*ways)%mod) * inv_fact[size_of] % mod;
            my_size += size_of;
        }
        return {(tot_ways*fact[my_size-1])%mod, my_size};
    }
};