class Solution {
public:
    
    int n;
    int ov[12][12];
    int overlap(int last,int i){
        if(last==n) return 0;
         return ov[last][i];
    }
    
    int minStr(vector<string>& words ,int mask,int last,vector<vector<int>>& dp){
        
        if(mask==(1<<n)-1) return 0;
        int ans=1e9;
        if(dp[mask][last]!=-1) return dp[mask][last];
        for(int j=0;j<words.size();j++){
         
            if((mask&(1<<j))==0){ 
               ans=min(ans,(int) words[j].size()-overlap(last,j)+minStr(words,mask|(1<<j) ,j,dp) ); 
            }
        }
        return dp[mask][last]=ans;
        
    }
    
    string shortestSuperstring(vector<string>& words) {
        n=words.size();
        string ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ov[i][j]=0;
                for(int l=min(words[i].size(),words[j].size());l>=1;l--){
                   if( words[j].substr(0,l)==words[i].substr(words[i].size()-l)) {
                       ov[i][j]=l;
                       break;
                   } 
                    
                } 
            }
        }
        vector<vector<int>> dp(1<<n,vector<int>(n+1,-1));
        minStr(words,0,n,dp);
        
        int mask=0;
        int last=n;
        

       while(mask!=(1<<n)-1){
            for(int j=0;j<n;j++){
         
               if((mask&(1<<j))==0){ 
                   if(dp[mask][last]==(int) words[j].size()-overlap(last,j)+minStr(words,mask|(1<<j) ,j,dp)){
                       ans=ans+words[j].substr(overlap(last,j));
                       mask=mask|(1<<j);
                       last=j;
                       break;
                   } 
                }
            }  
       }
        
      return ans;
    }
};
