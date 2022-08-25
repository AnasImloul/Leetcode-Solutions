// Runtime: 9 ms (Top 75.92%) | Memory: 9.2 MB (Top 31.64%)
class UnionFind {
    public:

    int* parent;
    int* rank;

    UnionFind(int n){
        rank = new int[n];
        parent = new int[n];

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // collapsing find
    int Find(int node){
        // if parent of node is itself
        if(parent[node] == node){
            return node;
        }
        return parent[node] = Find(parent[node]);
    }

    // union by rank
    void Union(int u, int v){
        // find the parent nodes of u and v
        u = Find(u);
        v = Find(v);

        // if u and v don't belong to the same set
        if(u != v){
            if(rank[u]<rank[v]){
                swap(u,v);
            }

            // attaching the lower rank tree with the higher rank one
            parent[v] = u;

            // if ranks are equal increase the rank of u
            if(rank[u]==rank[v]){
                rank[u]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind UF = UnionFind(1001);

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            // if adding this edge creates a cycle
            if(UF.Find(u) == UF.Find(v)){
                return {u,v};
            }

            // add u and v to the same set
            UF.Union(u,v);
        }

        // if no cycle was found
        return {-1};
    }
};