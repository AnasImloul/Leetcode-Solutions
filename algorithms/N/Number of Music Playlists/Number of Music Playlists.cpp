class Solution {
public:
    using ll = long long;
    int N, target;
    int dp[102][102];
    int mod = 1e9+7;
    ll solve(int unique, int taken, int k)
    {
        
        if(unique > N || (taken == target && unique < N))
            return 0;
        if(taken == target)
            return 1;
        
        int ans = 0;
        
        if(dp[unique][taken] != -1)
            return dp[unique][taken];
        
        // first time adding a new song
        ans = (solve(unique+1, taken+1, k) * (N-unique)) % mod;
        
        // repeat from already chosen songs
        int val = solve(unique, taken+1, k) * max(0, unique-k) % mod;
        ans += val;
        
        ans %= mod;
        return dp[unique][taken] = ans;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        N = n, target = goal;
        return solve(0, 0, k);
    }
};
