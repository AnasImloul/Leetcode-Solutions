Time: O(n)  Space: O(n)
--> TLE
class Solution {
public:
    bool canWinNim(int n) {
        if(n<4)
            return true;
        vector<bool> dp(n+1);
        dp[1]=true,dp[2]=true,dp[3]=true,dp[4]=false;
        for(int i=5;i<n+1;i++){
            if(dp[i-1]==false or dp[i-2]==false or dp[i-3]==false)
                dp[i]=true;
        }
        return dp[n];
    }
};


Time: O(1)  Space: O(1)

class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0)
            return false;
        return true;
    }
};
