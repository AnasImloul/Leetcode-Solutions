// Runtime: 54 ms (Top 93.4%) | Memory: 16.26 MB (Top 14.3%)

class Solution {
public:
unordered_map<int,int>m;
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        int ind=-1,ans=1e8;
       for(int i=0;i<n;i++)
       {
           queue<pair<int,int>>q;
           q.push({i,0});
           vector<int>dis(n,1e8);
           dis[i]=0;
           while(!q.empty())
           {
               int node=q.front().first;
               int wt=q.front().second;
               q.pop();
               for(auto x:adj[node])
               {
                   int node1=x.first;
                   int wt1=x.second;
                   if(wt+wt1<dis[node1])
                   {
                       dis[node1]=wt+wt1;
                       q.push({node1,wt+wt1});
                   }
               }
           }
           int c=0;
           for(int i=0;i<dis.size();i++)
           {
               if(dis[i]<=threshold)
               {
                   c++;
               }
           }
           if(c<=ans)
           {
               ans=c;
               ind=max(ind,i);
           }
           
       }
       return ind;


    }
};