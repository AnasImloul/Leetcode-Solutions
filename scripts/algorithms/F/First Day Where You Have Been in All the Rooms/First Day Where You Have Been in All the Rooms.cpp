// Runtime: 301 ms (Top 34.09%) | Memory: 97.1 MB (Top 92.27%)
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        int mod = 1e9 + 7;
        long long dp[n];
        dp[0] = 0;

        for(int i = 1 ; i < n ; i++)
        {
            if(dp[i-1] == nextVisit[i-1])
                dp[i] = dp[i-1] + 2;
            else
                dp[i] = (2 + 2*dp[i-1] + mod - dp[nextVisit[i-1]])%mod;
        }

        return (int) dp[n-1]%mod;
    }
};