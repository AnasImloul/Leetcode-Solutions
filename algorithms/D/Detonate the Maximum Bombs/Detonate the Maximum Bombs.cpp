class Solution {
public:
    double eucDis(int x1,int y1,int x2,int y2)
    {
        double temp=pow(x1-x2,2)+pow(y1-y2,2);
        return sqrt(temp);
    }
    void dfs(int node,vector<int>&vis,vector<int>graph[],int &c)
    {
        c++;
        vis[node]=1;
        for(auto i:graph[node])
        {
            if(!vis[i])
            {
                dfs(i,vis,graph,c);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        vector<int>graph[n+1];
        int i,j;
        for(i=0;i<n;i++)
        {
            bombs[i].push_back(i);
        }
        for(i=0;i<n;i++)
        {
            
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                double dis1=eucDis(bombs[i][0],bombs[i][1],bombs[j][0],
                               bombs[j][1]);
                
                if(dis1<=bombs[i][2])
                {
                    int node1=bombs[i][3];
                    int node2=bombs[j][3];
                    graph[node1].push_back(node2);
                }
            }
        }
       
        int maxi=1;
        for(i=0;i<n;i++)
        {
            int c=0;
            if(graph[i].empty())
                continue;
            vector<int>vis(n+1,0);
            
            dfs(i,vis,graph,c);   
            maxi=max(maxi,c);
            
            
        }
        return maxi;
    }
};
