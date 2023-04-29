class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //create an adjacency list
        unordered_map<int , set<int> > adj;
        int maxi;

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            maxi = max(maxi ,max(u,v));

            adj[u].insert(v);
            adj[v].insert(u);
        }

        for(auto i : adj){
            if(i.second.size() == maxi-1)
                return i.first;
        }
        return -1;
    }
};