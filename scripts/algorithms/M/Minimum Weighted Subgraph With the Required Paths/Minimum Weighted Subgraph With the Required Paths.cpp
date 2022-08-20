// Runtime: 1059 ms (Top 53.95%) | Memory: 144 MB (Top 68.42%)

typedef long long ll;

class Solution {
private:
    const ll kInf = 1e18;
    vector<ll> Dijkstra(vector<vector<pair<int, ll>>>& adj, int src) {
        int n = adj.size();
        vector<ll> dist(n, kInf);
        dist[src] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        // pq contains pairs of <the current distance estimate from src to id, id>
        pq.push(make_pair(0, src));
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (d != dist[cur]) continue;
            for (auto [nei, w] : adj[cur]) {
                if (dist[nei] > d + w) {
                    dist[nei] = d + w;
                    pq.push(make_pair(dist[nei], nei));
                }
            }
        }
        return dist;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        // build the graphs
        vector<vector<pair<int, ll>>> adj(n);
        vector<vector<pair<int, ll>>> rev(n); // the graph with reversed edges
        int u, v, w;
        for (auto& e : edges) {
            u = e[0], v = e[1], w = e[2];
            adj[u].push_back(make_pair(v, w));
            rev[v].push_back(make_pair(u, w));
        }
        // Dijkstra
        vector<ll> dist_from_src1 = Dijkstra(adj, src1);
        vector<ll> dist_from_src2 = Dijkstra(adj, src2);
        vector<ll> dist_to_dest = Dijkstra(rev, dest);
        // find the smallest w[i]
        ll ans = kInf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist_from_src1[i] + dist_from_src2[i] + dist_to_dest[i]);
        }
        return ans == kInf ? -1 : ans;
    }
};