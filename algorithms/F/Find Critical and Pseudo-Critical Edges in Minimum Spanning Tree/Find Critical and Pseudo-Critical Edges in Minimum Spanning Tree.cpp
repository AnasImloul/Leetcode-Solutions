class UnionFind{
private:
    vector<int> parent_;
    vector<int> rank_;
    int sets_;
public:
    UnionFind(int n)
    {
        init(n);
    }
    void init(int n)
    {
        sets_ = n;
        parent_.resize(n);
        rank_.resize(n);
        iota(parent_.begin(),parent_.end(),0);
        fill(rank_.begin(),rank_.end(),1);
    }
    int find(int u)
    {
        return parent_[u] == u ? u: parent_[u] = find(parent_[u]);
    }
    bool join(int u,int v)
    {
        u = find(u);
        v = find(v);

        if(u==v)
        {
            return false;
        }
        
        if(rank_[u]<rank_[v])
        {
            swap(u,v);
        }

        rank_[u] += rank_[v];
        parent_[v] = u;

        sets_ --;
        return true;
    }
    bool united()
    {
        return sets_ == 1;
    }
};
class Solution {
public:
    vector<int> edges_idx_;
    int kruskal(const int n, const int removed_edge_idx,const int init_edge_idx,
    const vector<vector<int>> &edges)
    {
        UnionFind graph(n);
        int edges_size = edges.size();
        int total = 0;

        if(init_edge_idx != -1)
        {
            graph.join(edges[init_edge_idx][0],edges[init_edge_idx][1]);
            total += edges[init_edge_idx][2];
        }

        
        for(int i = 0; i<edges_size; ++i)    
        {
            int edge_idx = edges_idx_[i];

            if(edge_idx == removed_edge_idx)
            {
                continue;
            }

            int u = edges[edge_idx][0];
            int v = edges[edge_idx][1];

            if(graph.join(u,v))
            {
                total+= edges[edge_idx][2];
            }
        }
        
        return graph.united() ? total : INT_MAX;

    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
       int edges_size = edges.size();

       edges_idx_.resize(edges_size);

       iota(edges_idx_.begin(),edges_idx_.end(),0);
       
       sort(edges_idx_.begin(),edges_idx_.end(),[&edges](int a, int b){
           return edges[a][2] < edges[b][2];
       });

       int mst = kruskal(n,-1,-1,edges);
       

       vector<int> critical;
       vector<int> psudo;
       
       for(int i = 0; i< edges_size; ++i)
       {
           int edge_idx = edges_idx_[i];
           int total = kruskal(n,-1,edge_idx,edges);
           
           if(total == mst)
           {
               total = kruskal(n,edge_idx,-1,edges);
               if(total > mst)
               {
                   critical.push_back(edge_idx);
               }
               else{
                   psudo.push_back(edge_idx);
               }
           }
       }

       return {critical,psudo};
       
    }
};
