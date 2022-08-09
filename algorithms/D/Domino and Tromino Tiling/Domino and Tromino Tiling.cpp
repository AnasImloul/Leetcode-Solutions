class Solution {
public:
	#define ll long long
	const int mod = 1e9 + 7;
	int numTilings(int n) {
		vector<vector<ll>> dp(n+1,vector<ll>(4,0));

		dp[0][3]=1;

		for(int i=1; i<=n; i++){
			dp[i][0] += dp[i-1][3];

			dp[i][1] += (dp[i-1][2] + dp[i-1][0]) % mod;            

			dp[i][2] += (dp[i-1][1] + dp[i-1][0]) % mod;

			dp[i][3] += (dp[i-1][3] + dp[i-1][1] + dp[i-1][2] + dp[i-1][0]) % mod;
		}

		return dp[n][3];
	}
};
