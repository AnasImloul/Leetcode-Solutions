class Solution {
public:
    vector<vector<int>> dp;
    int find(int n){   // return the compressed length of 'n' similiar char
        if(n==1) return 1;
        else if(n>1 && n<10) return 2;
        else if(n>=10 && n<100) return 3;
        else return 4;
    }
    int dfs(string &s,int in,int k){
        if(k<0) return INT_MAX;
        if(in>=s.size() || (s.size()-in)<=k) return 0;
        if(dp[in][k]!=-1) return dp[in][k];
        
        int n = 0, t = 0,i = in;  char ch = s[in];  // n = no. of contigous same char after removing 't' char in-between.
        int re = dfs(s,in+1,k-1);  // Min length after removing current char from [in+1 to s.size()-1]
        
        for(; i<s.size() && t<=k;++i){
            if(s[i]==ch) n++;
            else re = min(re,find(n)+dfs(s,i,k-t++)); // check for subseq [i to s.size()]
        }
        if(t<=k) re = min(re,find(n)+dfs(s,i,k-t));
        return dp[in][k] = re;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        dp = vector<vector<int>>(s.size()+1,vector<int>(k+1,-1));
        return dfs(s,0,k);
    }
};
