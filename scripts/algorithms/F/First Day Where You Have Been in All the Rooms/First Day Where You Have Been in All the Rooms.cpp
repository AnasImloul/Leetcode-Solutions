#define ll long long 
int  mod=1e9+7;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
          int n=nextVisit.size();
          vector<vector<ll>>dp(n,vector<ll>(2,0));
          dp[0][0]=2;
          dp[0][1]=1;
          for(int i=1;i<n;i++)
          {   dp[i][1]=dp[i-1][0]+1;
               if(i==n-1)break;
              dp[i][0]=(dp[i][1]+(dp[i-1][0]-dp[nextVisit[i]][1])+2)%mod;  
          }
          return (dp[n-1][1]+mod-1)%mod;
    }
};