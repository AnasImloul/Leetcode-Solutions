class Solution {
public:
    int cal(int node, int n, vector<vector<pair<int,int>>> &graph, int maxd) {
        vector<int> dist(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int>>> pq;
        pq.push({0, node});
        dist[node] = 0;
        while(!pq.empty()) {
            int d = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            if(dist[node] != d) continue;
            for(auto nbr : graph[node]) {
                int u = nbr.first;
                int len = nbr.second;
                if(dist[u] > len + d) {
                    dist[u] = len+d;
                    pq.push({dist[u], u});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(dist[i] <= maxd) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        int maxcnt = INT_MAX;
        int resnode = 0;
        for(int i = 0; i < n; i++) {
            int cnt = cal(i, n, graph, distanceThreshold);
            if(maxcnt >= cnt) {
                maxcnt = cnt;
                resnode = i;
            }
        }
        return resnode;
    }
};
