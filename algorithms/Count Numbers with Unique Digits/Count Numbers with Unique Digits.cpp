// Recursion 
class Solution {
public:
    int solve(int n){
        if (n==0)  return 1; 
        int tmp =9 ; 
        int ans = 9 ;
        for ( int i =1 ; i<n ; i++)
            ans*=tmp--; 
        return dp[n]=ans + solve(n-1); 
    }
    int countNumbersWithUniqueDigits(int n) {
        return solve(n); 
    }
};

//Memoization
class Solution {
public:
    int dp[9]={1};
    int solve(int n){
        if ( n==0 || dp[n]!=0) return dp[n]; 
        int tmp =9 ; 
        int ans = 9 ;
        for ( int i =1 ; i<n ; i++)
            ans*=tmp--; 
        return dp[n]=ans + solve(n-1); 
    }
    int countNumbersWithUniqueDigits(int n) {
        return solve(n); 
    }
};
//Dynamic Programming
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum=1,c=9;
        vector<int> dp(n+2);
        dp[0]=1,dp[1]=10;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]*c+sum;
            sum+=dp[i-1];
            c--;
        }
        return dp[n];
    }
};
