class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        //jai shri ram
        int ans=0;
        vector<bool>block(25*int(1e4)+1,0);
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(auto x:mines){
            int a=x[0],b=x[1];
            block[a*n+b]=true;
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(block[i*n+j]){
                    sum=0;
                }else {
                    sum+=1;
                }
                dp[i][j]=sum;
            }
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(block[i*n+j]){
                    sum=0;
                }else sum+=1;
                dp[i][j]=min(dp[i][j],sum);
            }
        }
        for(int j=n-1;j>=0;j--){
            int sum=0;
            for(int i=n-1;i>=0;i--){
                if(block[i*n+j]){
                    sum=0;
                }else sum+=1;
                dp[i][j]=min(dp[i][j],sum);
            }
        }
        for(int i=n-1;i>=0;i--){
            int sum=0;
            for(int j=n-1;j>=0;j--){
                if(block[i*n+j]){
                    sum=0;
                }else sum+=1;
                dp[i][j]=min(dp[i][j],sum);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
