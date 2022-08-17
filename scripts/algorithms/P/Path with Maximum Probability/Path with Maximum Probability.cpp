class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        vector<bool> visited(n, false);
        vector<double> values(n, 0.0);
        values[start] = 1.0;
        while(!pq.empty()){
            double currValue = pq.top().first, currNode = pq.top().second;
            pq.pop();
            visited[currNode] = true;
            for(int i = 0; i < graph[currNode].size(); ++i){
                double weight = graph[currNode][i].second;
                int nextNode = graph[currNode][i].first;
                if(visited[nextNode] == false){
                    double nextProb = currValue * weight;
                    if(nextProb > values[nextNode])
                        values[nextNode] = nextProb;
                    pq.push({nextProb, nextNode});
                }
            }
        }
        return values[end] == 0.0 ? 0.0 : values[end];
    }
};
