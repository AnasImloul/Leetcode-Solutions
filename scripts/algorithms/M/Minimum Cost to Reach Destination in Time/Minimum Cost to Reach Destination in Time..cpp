// Runtime: 375 ms (Top 31.89%) | Memory: 50.10 MB (Top 35.83%)

class Solution {
public:
    vector<vector<int>> adj[1001];
    int cost[1001], time[1001];
    
    int dijkstra(int src, int dest, int maxTime) {
        
        for (int i = 1; i <= dest; i++) {
            cost[i] = INT_MAX;
            time[i] = INT_MAX;
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[src], time[src], src});
        
        while (pq.empty() == 0) {
            vector<int> z = pq.top(); pq.pop();
            
            int c = z[0];     // cost
            int t = z[1];     // time
            int v = z[2];     // vertex
            
            for (int i=0;i<adj[v].size();i++) {
                
			    // if this edge does not cause the time to exceed maxTime
                if (t + adj[v][i][1] <= maxTime) {
                    
				    // if cost will decrease
                    if (cost[adj[v][i][0]] > c + adj[v][i][2]) {
                        cost[adj[v][i][0]] = c + adj[v][i][2];
                        
                        time[adj[v][i][0]] = t + adj[v][i][1];
                        pq.push({cost[adj[v][i][0]], time[adj[v][i][0]], adj[v][i][0]});
                    }
                    
					// if time will decrease
                    else if (time[adj[v][i][0]] > t + adj[v][i][1]) {
                        time[adj[v][i][0]] = t + adj[v][i][1];
                        pq.push({c + adj[v][i][2], time[adj[v][i][0]], adj[v][i][0]});
                    }
                }
            }
        }
        
        return cost[dest];
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int i, x, y, t, e = edges.size(), n = fee.size();
        
        for (i=0;i<e;i++) {
            x = edges[i][0];
            y = edges[i][1];
            t = edges[i][2];
            
            adj[x].push_back({y, t, fee[y]});
            adj[y].push_back({x, t, fee[x]});
        }
        
        cost[0] = fee[0];
        time[0] = 0;
        
        int ans = dijkstra(0, n-1, maxTime);
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};
