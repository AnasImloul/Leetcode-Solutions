// Runtime: 1454 ms (Top 5.06%) | Memory: 53.4 MB (Top 75.63%)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target ) return 0;
        queue<int> q;
        vector<bool> vis(routes.size(), 0);
        vector<vector<int>> g(routes.size());
        vector<unordered_set<int>> rout(routes.size());

        //create graph between the buses - which buses are connected to single stop
        for(int i = 0; i < routes.size(); ++i){
            for(auto r: routes[i]){
                rout[i].insert(r);
                for(int j = 0; j < i; ++j){
                    if(rout[j].find(r) != rout[j].end()){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
            if(rout[i].find(source) != rout[i].end()){
                q.push(i);
                vis[i] = true;
            }
        }

        //search path to target using bfs
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            level++;
            while(n--){
                int node = q.front();
                q.pop();
                if(rout[node].find(target) != rout[node].end()) return level;
                for(auto i: g[node]){
                    if(vis[i] == false){
                        q.push(i);
                        vis[i]= true;
                    }
                }
            }
        }
        return -1;
    }
};