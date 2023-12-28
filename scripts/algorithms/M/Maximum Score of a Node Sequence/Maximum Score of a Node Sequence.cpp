// Runtime: 582 ms (Top 20.33%) | Memory: 189.00 MB (Top 26.83%)

/* 
    Time: O(V+E)
    Space: O(V+E)
    Tags: Graph, Set, Sorting, Greedy
    Difficulty: H
*/

class Solution {
public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
        set<pair<int, int>> graph[scores.size()];
        for (auto edge : edges) {
            graph[edge[0]].insert({scores[edge[1]], edge[1]});
            graph[edge[1]].insert({scores[edge[0]], edge[0]});
            if (graph[edge[0]].size() > 3) graph[edge[0]].erase(graph[edge[0]].begin());
            if (graph[edge[1]].size() > 3) graph[edge[1]].erase(graph[edge[1]].begin());
        }
        int res = -1;
        for (auto edge : edges) {
            int ans = scores[edge[0]] + scores[edge[1]];
            for (auto node1 : graph[edge[0]]) {
                for (auto node2 : graph[edge[1]]) {
                    if (node1.second != edge[0] && node1.second != edge[1] && node2.second != edge[0] && node2.second != edge[1] && node2.second != node1.second)
                        res = max(res, ans + node1.first + node2.first);
                }
            }
        }
        return res;
    }
};
