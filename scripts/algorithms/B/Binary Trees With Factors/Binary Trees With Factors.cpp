// Runtime: 122 ms (Top 49.07%) | Memory: 8.4 MB (Top 98.09%)
class Solution {
public:
    const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        int n=arr.size();

        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
            int l=0,r=i-1;
            while(l<=r){
                if(arr[l]*1LL*arr[r]==arr[i]*1LL){
                    if(l!=r) dp[i]=(dp[i]+(dp[l]*1LL*dp[r]%mod*2LL%mod))%mod;
                    else dp[i]=(dp[i]+(dp[l]*1LL*dp[r]%mod))%mod;
                    l++,r--;
                } else if(arr[l]*1LL*arr[r]>arr[i]*1LL) r--;
                else l++;
            }
        }

        int ans=0;
        for(auto i:dp) ans=(ans+i)%mod;
        return ans;
    }
};