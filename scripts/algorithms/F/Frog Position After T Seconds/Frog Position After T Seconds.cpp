// Runtime: 29 ms (Top 69.74%) | Memory: 16.4 MB (Top 15.95%)
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> adjList;
        for(const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // BFS way
        queue<pair<int, double>> Q;
        Q.push({1, 1.0});
        int time = 0;
        vector<int> visited(n+1, false);

        while(not Q.empty()) {
            int size = Q.size();

            if (time > t) break;

            while(size--) {
                auto pp = Q.front(); Q.pop();
                int node = pp.first;
                double prob = pp.second;

                visited[node] = true;

                // Count the unvisited nbr
                int nbrCount = 0;
                for(auto& nbr : adjList[node]) {
                    if (not visited[nbr]) nbrCount++;
                }

                if (node == target) {
                    if (time == t) return prob;
                    if (time < t) {
                        // Check if any unvisited ? if yes, then frog would jump there and not be able to jump back here
                        if (nbrCount > 0) return 0.0;

                        // else return the same prob
                        return prob;
                    }
                }

                for(auto& nbr : adjList[node]) {
                    if (not visited[nbr]) {
                        // update the prob as it will be divided by number of nbr
                        Q.push({nbr, (prob * (1.0/nbrCount))});
                    }
                }
            }

            time++;
        }

        return 0.0;
    }
};