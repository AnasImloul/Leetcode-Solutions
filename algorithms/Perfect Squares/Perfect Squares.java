



class Solution {
    public int numSquares(int n) {
        
        ArrayList<Integer> perfect_squares = new ArrayList<>();
        int i=1;
        while(i*i <= n){
            perfect_squares.add(i*i);
            i++;
        }
        Integer[][] dp = new Integer[n+1][perfect_squares.size()+1];
        int answer = helper(n , perfect_squares , perfect_squares.size()-1,dp);
        return answer;
    }
    
    public int helper(int n , ArrayList<Integer> coins ,int i,Integer[][] dp){
        
        if(n == 0){
            return 0;
        }
        if(i<0){
            return 999999;      //  I'm not taking INT_MAX here, since int variables will overflow with (1 + INT_MAX)
			                             // just take any number greater than constraint ( 10^4) 
        }
        if(dp[n][i] != null){
            return dp[n][i];
        }
        int nottake = 0 + helper(n , coins, i-1,dp);
        int take = 9999999;
        if(coins.get(i) <= n){
            take = 1 + helper(n-coins.get(i),coins,i,dp );          
        }
        dp[n][i] = Math.min(nottake,take);
        return dp[n][i];
        
        
        
    }
    
    
}



