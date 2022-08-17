class Solution {
public:
    vector<int>parent,rank;
    
    void initialize(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findPar(int v){
        if(v==parent[v]) return v;
        return parent[v]=findPar(parent[v]);
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int s=edgeList.size();
        int m=queries.size();
        parent.resize(n);
        rank.resize(n);
        initialize(n);
        
        vector<vector<int>>edges,q;
        for(int i=0;i<s;i++){
            vector<int>t;
            t.push_back(edgeList[i][2]); t.push_back(i);
            edges.push_back(t);
        }
        for(int i=0;i<m;i++){
            vector<int>t;
            t.push_back(queries[i][2]); t.push_back(i);
            q.push_back(t);
        }
        
        sort(edges.begin(),edges.end());
        sort(q.begin(),q.end());
        
        vector<bool>ans(m);
        int start=0;
        
        for(int i=0;i<m;i++){
            int weight=q[i][0];
            int qv1=queries[q[i][1]][0];
            int qv2=queries[q[i][1]][1];
            for(int j=start;j<s;j++){
                if(edges[j][0]<weight){
                    int v1=edgeList[edges[j][1]][0];
                    int v2=edgeList[edges[j][1]][1];
                    int u=findPar(v1);
                    int v=findPar(v2);
                    if(u!=v){
                        //union
                        if(rank[u]<rank[v])
                            parent[u]=v;
                        else if(rank[v]<rank[u])
                            parent[v]=u;
                        else
                            parent[v]=u,rank[u]++;
                    }
                    start++;
                    
                }
                else
                    break;
                
            }
            if(findPar(qv1)==findPar(qv2))
                ans[q[i][1]]=true;
            else
                ans[q[i][1]]=false;
        }
        return ans;
    }
};
