class Solution {
public:
    int minimumTime(string s) {
        int n=s.length();
        vector<int>dp(n,0);
        if(s[n-1]=='0'){
            dp[n-1]=0;
        } else {
            dp[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0')dp[i]=dp[i+1];
            if(s[i]=='1'){
                dp[i]=2+dp[i+1]; // consider current index to be a middle one and remove
                dp[i]=min(dp[i],n-i); // or remove all to the right
            }
        }
		// now go from left to right
        int ans=dp[0];
        for(int i=0;i<n-1;i++){
            ans=min(ans,i+1+dp[i+1]); // cost of removing all from left and dp[i+1]
        }
        ans=min(ans,n); // taking overall minimum
        return ans;
    }
};
