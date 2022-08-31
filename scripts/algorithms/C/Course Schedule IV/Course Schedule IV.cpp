// Runtime: 270 ms (Top 87.54%) | Memory: 69.3 MB (Top 32.97%)
// question similar to find all ancestors of current node

class Solution {

public:

    void dfs(vector<vector<int>>&adj,vector<set<int>>&Anc,int u,int par,vector<int>&vis)
    {
        if( vis[u] != 0 )
            return ;

        vis[u] = 1 ;

        for(auto&v:adj[u])
        {
            if( vis[v] == 0 )
            {
                Anc[v].insert(par) ;
                dfs(adj,Anc,v,par,vis) ;
            }
        }

        return ;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n = numCourses ;
        vector<vector<int>>adj(n);
        vector<set<int>>Anc(n);
        vector<bool>ans;

        for(auto&edge:prerequisites)
        {
            adj[edge[0]].push_back(edge[1]) ;
        }

        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            dfs(adj,Anc,i,i,vis) ;
        }

        for(auto&EachQuery:queries)
        {
            if( Anc[EachQuery[1]].find(EachQuery[0]) != Anc[EachQuery[1]].end() )
                ans.push_back(true);
            else
                ans.push_back(false) ;
        }
        return ans ;
    }

};
