/**
 * 
 * k = current number of seats
 * i = current position
 * Time complexity = O(N)
 * 
**/
class Solution {
public:
    const int MOD = (int)1e9 + 7;
    long long dp[100001][3];
    long long getAns(string & a, int i, int k) {
        if(i >= a.size()) {
            return k == 2;
        }
        
        if(dp[i][k] != -1)return dp[i][k];
        
		//if total number of seats in current segment is 2
        if(k == 2) {
            if(a[i] == 'P') {
				//choice either to add divider before current plant or not.
                return dp[i][k] = (getAns(a, i + 1, 0) % MOD + getAns(a, i + 1, k) % MOD) % MOD;
            }
            else {
				//necessary to put a divider before current seat, as current count of seat is 2
                return dp[i][k] = getAns(a, i + 1, 1) % MOD;
            }
        }
        else {
			//current seat is less than 2 so, move ahead
            return dp[i][k] = getAns(a, i + 1, k + (a[i] == 'S')) % MOD;
        }
        
        
    }
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return getAns(corridor, 0, 0); 
    }
};
