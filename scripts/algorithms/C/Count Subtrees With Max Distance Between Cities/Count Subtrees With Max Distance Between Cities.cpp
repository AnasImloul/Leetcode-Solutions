class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        //INT_MAX/2-1 used to avoid overflow
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX/2-1));
        for (auto e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            graph[u][v] = graph[v][u] = 1;
        }
        
        //floyed-warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        
        vector<int> res(n-1, 0);
        
        
        /* Check for each combination of nodes and see if it's a subtree or not.
        If it's a subtree then see maximum distance that can be reached.*/
        
        //Each subtree
        //sub = subtree
        for (int sub = 0; sub < (1 << n); sub++) {
            // Number of nodes = nodes
            int nodes = __builtin_popcount(sub);
            // edges
            int edges = 0;
            //dist = distance
            int dist = 0;
            for (int i = 0; i < n; i++)
                if (sub & (1 << i)) {
                    for (int j = i + 1; j < n; j++) 
                        if (sub & (1 << j)) {
                            // if i to j edge increment e
                            edges += graph[i][j] == 1;
                            // maximum distance
                            dist = max(dist, graph[i][j]);
                    }
            }
            // chech its a subtree and distance > 0 if it's then its a subtree having max d distance
            if (edges == nodes - 1 && dist > 0) {
                res[dist - 1]++;
            }
        }
        
        return res;
		//Please upvote
    }
};
