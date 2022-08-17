static int MOD=1e9+7;
class Solution {
public:
    int delay,forget;
    vector<long> memo;
    // Total number of people who would have found out about the secret by the nth day.
    long dp(int n) {
        if(!n)
            return 0;
        if(memo[n]!=-1)  // Return cached result if exists.
            return memo[n];
		// Current contribution of 1 person who knows the secret
        long result=1;
        for(int i=delay;i<forget;i++)       // Number of people that the secret will be forwarded to
            if(n-i>=0)
                result=(result+dp(n-i))%MOD;
        return memo[n]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->delay=delay;
        this->forget=forget;
        memo.resize(n+1,-1);
        return (dp(n)-dp(n-forget)+MOD)%MOD;    // Subtract the people who found out by the `n-forget` day as observed.
    }
};
