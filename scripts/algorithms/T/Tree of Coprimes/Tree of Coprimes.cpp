// Runtime: 1567 ms (Top 22.85%) | Memory: 170.8 MB (Top 88.79%)

class Solution {
public:
    vector<int> adj[100009];
    vector<int> d[55];
    int dis[100009];
    void dfs(vector<int>& nums,vector<int> &ans,int i,int p,int h1)
    {
        int h=nums[i];
        dis[i]=h1;
        ans[i]=-1;
        int val=-1;
        for(int w=1;w<=50;w++)
        {
            if(__gcd(h,w)==1)
            {
                if(d[w].size())
                {
                    int u=d[w].back();
                    if(dis[u]>val)
                    {
                        val=dis[u];
                        ans[i]=u;
                    }
                }
            }
        }
        d[h].push_back(i);
        for(auto x:adj[i])
        {
            if(x==p) continue;
            dfs(nums,ans,x,i,h1+1);
        }
        d[h].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n);
        dfs(nums,ans,0,-1,0);
        return ans;
    }
};
