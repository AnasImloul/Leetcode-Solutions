// Runtime: 389 ms (Top 31.30%) | Memory: 61.8 MB (Top 53.68%)
class DSU{
private:
    vector<int> parent,rank ;
public:
    DSU(int n){
        rank.resize(n,1) ;
        parent.resize(n) ;
        iota(begin(parent),end(parent),0) ;
    }

    int find_parent(int node){
        if(node == parent[node]) return node ;
        return parent[node] = find_parent(parent[node]) ;
    }
    void Union(int u , int v){
        int U = find_parent(u) , V = find_parent(v) ;
        if(U == V) return ;
        if(rank[U] < rank[V]) swap(U,V) ;
        rank[U] += rank[V] ;
        parent[V] = U ;
    }
    int getRank(int node){
        return rank[parent[node]] ;
    }

};

class Solution {
public:
    vector<bool> dp ;
    vector<bool> hasApple ;
    vector<int> adj[100001] ;
    vector<int> visited ;

    void dfs(int src){
        visited[src] = 1 ;
        for(auto &nbr : adj[src]){
            if(!visited[nbr]){
                dfs(nbr) ;
                dp[src] = dp[src] or dp[nbr] ;
            }
        }
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        DSU dsu(n) ;
        dp = hasApple ; visited.resize(n,0) ; this->hasApple = hasApple ;

        for(auto &x : edges) adj[x[0]].push_back(x[1]) , adj[x[1]].push_back(x[0]) ;
        dfs(0) ;

        int start = -1 ;
        for(int i = 0 ; i < n ; ++i ){
            if(!dp[i]) continue ;
            if(start == -1){
                start = i ; continue ;
            }
            dsu.Union(start,i) ;
        }

        return (dsu.getRank(0) - 1) * 2 ;
    }
};