class Solution {
public:
    int dp[101][101];
    int dfs(vector<string>& strs,int n,int in,int last){ // in = current index, last = closest previous non-deleted index
        if(in>=n) return 0;
        if(dp[in][last]) return dp[in][last];
        
        bool st = 1; 
        for(int i = 0; i<strs.size();++i){
            if(strs[i][in]<strs[i][last]) {st=0; break;} // check if strings are exicographically increasing
			                                             //w.r.t to current and last index
        }
        
        int re = INT_MAX;
        int l = last;
        if(in==last) l=in+1;
        re = 1+dfs(strs,n,in+1,l);  // delete the current index
        if(st) re = min(re, dfs(strs,n,in+1,in)); // if the strings are not lexicographically increasing,
                                           		//than only choice we have is to delete the in'th index
        
        return dp[in][last]=re;
    }
    int minDeletionSize(vector<string>& strs) {
        return dfs(strs,strs[0].size(),0,0);
    }
};
