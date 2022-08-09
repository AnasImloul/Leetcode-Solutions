class Solution {
public:
    int getheight(vector<int> a[],int sv,int n)
    {
        int lvl = 0;
        vector<int> vis(n,0);
        queue<int> q;
        q.push(sv);
        vis[sv] = 0;
        while(q.size())
        {
            int sz = q.size();
            lvl++;
            while(sz--)
            {
                int curr = q.front();
                q.pop();
                vis[curr] = 1;
                
                for(auto it:a[curr])
                {
                    if(vis[it]==0)
                    {
                        q.push(it);
                    }
                }
            }
        }
        return lvl;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> a[n];
        vector<int> indegree(n,0);
        for(auto it:edges)
        {
            a[it[0]].push_back(it[1]);
            a[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        //cutting leafs whose indegree is 1
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
                indegree[i]--;
            }
        }
        
        while(q.size())
        {
            int sz=q.size();
            ans.clear();
            while(sz--)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto it:a[curr])
                {
                    indegree[it]--;
                    if(indegree[it]==1)
                        q.push(it);
                }
            }
        }
        
        if(n==1)return {0};
        
        return ans;
        
        
        //brute force gives tle
//         int mn = INT_MAX;
//         unordered_map<int,vector<int>> mp;
//         for(int i = 0;i<n;i++)
//         {
//             int x = getheight(a,i,n);
//             mp[x].push_back(i);
            
//             // cout<<i<<" "<<x<<endl;
            
//             mn = min(mn,x);
//         }
        
//         return mp[mn];
        
    }
};
