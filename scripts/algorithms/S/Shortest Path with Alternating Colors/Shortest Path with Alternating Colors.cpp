#define red 1
#define blue 2
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        vector<vector<int>> visited(n, vector<int>(3, false));
        for(int i = 0;i<redEdges.size();i++)
        {
            graph[redEdges[i][0]].push_back({redEdges[i][1], red});
        }
              
        for(int i = 0;i<blueEdges.size();i++)
        {
            graph[blueEdges[i][0]].push_back({blueEdges[i][1], blue});
        }
        
        queue<tuple<int, int,int>> q;
        q.push({0, 0, 0});
        
        vector<int> res(n, INT_MAX);
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            int parent = get<0>(top);
            int step = get<1>(top);
            int color = get<2> (top);
            res[parent] = min(res[parent], step);
            if(visited[parent][color]) continue;
            visited[parent][color] = true;
            for(auto child:graph[parent])
            {
                if(color == child.second) continue;
                q.push(make_tuple(child.first, step+1, child.second));
            }
        }
        for(int i = 0;i<res.size();i++)
        {
            if(res[i]==INT_MAX) res[i] = -1;
        }
        return res;
    }
};