class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> graph;
		map<string, double> dist;
        map<string, bool> visited;
        for(int i=0;i<equations.size();i++){
            if(graph.count(equations[i][0])==0){
                graph[equations[i][0]] = {};
				visited[equations[i][0]] = false;
                dist[equations[i][0]] = DBL_MAX;
            }
            if(graph.count(equations[i][1])==0){
                graph[equations[i][1]] = {};
				dist[equations[i][0]] = DBL_MAX;
            }
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            if(values[i]!=0)
                graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            else
                graph[equations[i][1]].push_back({equations[i][0], -1});
        }
        vector<double> result;
        for(int i=0;i<queries.size();i++){
            if(graph.count(queries[i][0])==0 || graph.count(queries[i][1])==0){
                result.push_back(-1);
                continue;
            }
            if(queries[i][0] == queries[i][1]){
                result.push_back(1);
                continue;
            }
            for(auto j: visited)
                visited[j.first] = false;
            priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;
            dist[queries[i][0]] = 1;;
            pq.push({1, queries[i][0]});
            bool flag=false;
            while(!pq.empty()){
                auto k = pq.top();
                pq.pop();
                visited[k.second] = true;
                if(k.second==queries[i][1]){
                    flag=true;
                    result.push_back(dist[k.second]);
                    break;
                }
                for(int j=0;j<graph[k.second].size();j++){
                    if(!visited[graph[k.second][j].first])
                    {dist[graph[k.second][j].first] = dist[k.second] * graph[k.second][j].second;
                    pq.push({dist[graph[k.second][j].first], graph[k.second][j].first});}
                }
            }
            if(!flag)
                result.push_back(-1);
        }
        return result;
    }
};
