// Runtime: 354 ms (Top 22.54%) | Memory: 119.9 MB (Top 19.75%)
#define ll long long
class Solution {
public:
    vector<vector<ll> > dp;
    ll mod = 1e9 + 7;

    ll numWays(ll n, ll k) {
        if(k == 0 || k > n) return 0; // can't have no stick visible or more sticks visible than the total number of sticks
        if(n <= 2) return 1; // base condition

        if(dp[n][k] != -1) return dp[n][k]; // return if already calculated

        ll ans = 0;

        // select the tallest stick
        ans = (ans + numWays(n - 1, k - 1)) % mod;

        // select any of the n - 1 sticks that are not the tallest
        ans = (ans + ((n - 1) * numWays(n - 1, k))) % mod;

        return dp[n][k] = ans;
    }

    int rearrangeSticks(int n, int k) {
        dp = vector<vector<ll> >(n + 1, vector<ll>(k + 1, -1));
        return numWays(n, k);
    }
};