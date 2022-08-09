class Solution {
public:
    
    int fun(vector<int> &arr , int s , int f , int k , vector<vector<int>> &dp){
        if(k<0) return 0 ;
        if(dp[s][k]!=-1) return dp[s][k] ;
        int ans=0 ;
        if(s==f) ans=1 ;
        for(int i=0 ; i<arr.size() ; i++){
            if(i!=s) ans=(ans+fun(arr,i,f,k-abs(arr[s]-arr[i]),dp))%1000000007;
        }
     return dp[s][k]=ans ;   
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size()+1,vector<int>(fuel+1,-1)) ;
        int ans=fun(locations,start,finish,fuel,dp) ;
        return ans ;
    }
};
