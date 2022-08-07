class Solution {
public:
   vector<vector<int>>dp;
   string longestPalindrome(string s) {
       int n=s.size();
       dp = vector<vector<int>>(n+1,vector<int>(n+1,-1));
       isPalindrome(0,s.size()-1,s);
       int st=0,end=0;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(dp[i][j] && j-i>end-st){
                   st=i;
                   end=j;
               }
           }
       }
       return s.substr(st,end-st+1);
   }
   bool isPalindrome(int st, int end, string s){
       if(st==end || st>end)
           return 1;
       if(dp[st][end]==0 || dp[st][end]==1)
           return dp[st][end];
       
       dp[st][end] = (s[st]==s[end] && isPalindrome(st+1,end-1,s));
       //absba = 1
       isPalindrome(st,end-1,s);
       isPalindrome(st+1,end,s);
       return dp[st][end];
   }
};
