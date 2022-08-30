// Runtime: 945 ms (Top 20.47%) | Memory: 96.9 MB (Top 96.62%)
class Solution {
public:
    vector<int> Radj[50001],adj[50001] ,visited;
    int bfs(){
        int edges = 0 ;
        queue<int> q ;
        q.push(0) ;

        while(q.size()){
            auto src = q.front() ; q.pop() ;
            visited[src] = 1 ;

            for(auto &nbr : adj[src]){
                if(visited[nbr]) continue ;
                //this connection needs reverse orientation
                ++edges ;
                q.push(nbr) ;
            }

            for(auto &nbr : Radj[src]){
                if(visited[nbr]) continue ;
                q.push(nbr) ;
            }
        }

        return edges ;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        visited.resize(n,0);
        for(auto &x : connections) adj[x[0]].push_back(x[1]) , Radj[x[1]].push_back(x[0]);
        return bfs() ;
    }
};