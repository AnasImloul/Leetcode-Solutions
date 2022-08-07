class Solution {
private:
    vector<vector<int>>dp;
    bool backtrack(int curr,int &maxInt,int &desire,int mask,int player){
        if(dp[player][mask]!=-1){
            return dp[player][mask];
        } else {
            for(int i=1;i<=maxInt;i++){
                int nmask=(1<<(i-1));
                if((mask&nmask)==0){
                    if(curr+i>=desire or !backtrack(curr+i,maxInt,desire,mask+nmask,(player+1)%2)){
                        return dp[player][mask]=true;
                    }
                }
            }
            return dp[player][mask]=false;
        }
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        dp=vector<vector<int>>(2,vector<int>(1<<maxChoosableInteger,-1));
        if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal){
            return false;
        }
        int curr=0,mask=0;
        return backtrack(curr,maxChoosableInteger,desiredTotal,mask,0);
    }
};