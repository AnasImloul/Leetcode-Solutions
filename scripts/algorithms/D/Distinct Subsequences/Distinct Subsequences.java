class Solution {
    // We assume that dp[i][j] gives us the total number of distinct subsequences for the string s[0 to i] which equals string t[0 to j]
    int f(int i,int j,String s,String t,int dp[][]){
        //If t gets exhausted then all the characters in t have been matched with s so we can return 1 (we found a subsequence)
        if(j<0)
            return 1;
        // if s gets exhausted then there are characters remaining in t which are yet to be matched as s got exhausted they could not be matched so there is no distinct subsequence
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        //If both the characters in s[i] and t[j] match then we have two case
            //1) Either consider the i'th character of s and find the remaining distinct subsequences of s[0 to i-1] which equals t[0 to j-1] set i.e. f(i-1,j-1)
            //2) Do not consider s[i] so we are still at the same j'th character of t as we had not been considering s[i] matched with t[j] we check distinct subsequences of t[0 to j] in s[0 to i-1] i.e. f(i-1,j)
        if(s.charAt(i)==t.charAt(j)){
            dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        }
        // If both of them do not match then we consider the 2nd case of matching characters
        else{
            dp[i][j]=f(i-1,j,s,t,dp);
        } 
        return dp[i][j];
    }
    public int numDistinct(String s, String t) {
        int n=s.length();
        int m=t.length();
        int dp[][]=new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return f(n-1,m-1,s,t,dp);
    }
}
