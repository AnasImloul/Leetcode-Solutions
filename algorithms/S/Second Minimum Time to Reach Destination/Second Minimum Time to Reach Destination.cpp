class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // if the shortest path from 1 to n is of length L
        // find whether there is a path of length L+1
        // there is always a path of length L+2
        
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0]-1, v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // bfs from goal
        vector<int> d(n, 1e9);
        d[n-1] = 0;
        queue<int> q;
        q.push(n-1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == 1e9) {
                    d[nei] = d[cur] + 1;
                    q.push(nei);
                }
            }
        }
        
        // check the existence of a path with length = d[0]+1
        int len = d[0] + 2;
        q.push(0);
        bool done = false;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == d[cur]) {
                    len--;
                    done = true;
                    break;
                } else if (d[nei] == d[cur] - 1) {
                    q.push(nei);
                }
            }
            if (done) break;
        }
        
        // calculate the time needed
        // light : green in [0, c),  [2c, 3c), ... 
        //          red  in [c, 2c), [3c, 4c), ...
        int currTime = 0;
        //cout << len << '\n';
        for (int i = 0; i < len; i++) {
			if ((currTime / change) % 2 == 1)  // have to wait until the signal turns into green
                currTime = ((currTime / change) + 1) * change;    
            currTime += time;
        }
        return currTime;
    }
};
