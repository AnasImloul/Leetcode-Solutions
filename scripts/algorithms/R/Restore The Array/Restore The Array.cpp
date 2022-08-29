// Runtime: 140 ms (Top 39.77%) | Memory: 21.9 MB (Top 32.10%)
class Solution {
public:
    int mod=1e9+7;
    int f(int i,int k,string &s,vector<int> &dp){
        if(i==s.size()) return 1;//empty string
        if(dp[i]!=-1) return dp[i];//Memoization step
        if(s[i]=='0') return 0;//leading zeroes
        long long num=0;
        int ans=0;
        for(int j=i;j<s.size();j++){
            num=num*10+s[j]-'0';
            if(num>k) break;
            ans+=f(j+1,k,s,dp);//create num and call for next index
            ans%=mod;
        }
        return dp[i]=ans;//storing answer
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return f(0,k,s,dp);
        // dp[i]=total ways to
        // create possible arrays starting at index i
    }
};