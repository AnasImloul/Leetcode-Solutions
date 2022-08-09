class Solution {
public:
    
    int dp[501][501];
    
    int solve(vector<int>&v , int i ,int count ){
        
        if( i >= v.size() || count > v.size()/3 ) return 0 ;
        
        if(dp[i][count] !=  -1 ) return dp[i][count]; 
        
        int pick = v[i] + solve(v,i+2,count+1) ;
        int notPick = solve(v,i+1,count) ;
        
        return  dp[i][count] = max(pick,notPick) ;
        
    }
    
    
    int maxSizeSlices(vector<int>& slices) { 
        
     vector<int>v1 ;
     vector<int>v2 ;
        
     for(int i = 0 ; i < slices.size() ;i++){
         
         if( i != slices.size()-1 ) v1.push_back(slices[i]) ;
         if( i != 0 ) v2.push_back(slices[i]);
         
     }
     memset(dp,-1,sizeof(dp)) ;   
     int ans1 = solve(v1,0,0);
     memset(dp,-1,sizeof(dp)) ; 
     int ans2 = solve(v2,0,0);
        
     return max(ans1,ans2) ;
        
    }
};
