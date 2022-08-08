class Solution {
public:
    int dp[101][101] ;
    int solve(vector<int>&houses , int pos , int k){
        if(k < 0) return 1e9 ;
        if(pos >= houses.size()) return k ? 1e9 : 0 ; 
        if(dp[pos][k] != -1) return dp[pos][k] ;
        
        //at current position pos, spread the group from (pos upto j) and allot this whole group 1 mailbox.
        //start new neigbour at j + 1
        
        int ans = INT_MAX ;
        for(int j = pos ; j < houses.size() ; ++j ){
            int middle = (pos + j) / 2 , cost = 0 ;
            //cost calculation
            for(int i = pos ; i <= j ; ++i ) cost += abs(houses[middle] - houses[i]);
            
            ans = min(ans,cost + solve(houses,j + 1, k - 1)) ;
        }
        return dp[pos][k] = ans ;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(begin(houses),end(houses)) ;
        memset(dp,-1,sizeof(dp)) ;
        
        return solve(houses,0,k);
    }
};
