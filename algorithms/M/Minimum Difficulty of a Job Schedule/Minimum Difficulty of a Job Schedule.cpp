class Solution {
    vector<int> v;
    int len;
    int dp[301][11];
    int dfs(int idx, int d){//n*d
        if(idx>=len)
            return 0;
        if(d==1)
            return *max_element(v.begin()+idx,v.end());
        if(dp[idx][d]!=-1)
            return dp[idx][d];
        int maxx=INT_MIN;
        int res=INT_MAX;
        for(int i=idx;i<=len-d;i++){//n
            maxx=max(v[i],maxx);
            res=min(maxx+dfs(i+1,d-1),res);
        }
        return dp[idx][d]=res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        v=jobDifficulty;
        len=v.size();
        if(d>len)
            return -1;
        memset(dp,-1,sizeof(dp));
        return dfs(0,d);
    }
};
