class Solution {
    vector<vector<int>>res;
    vector<int>v{0};
public:
    void solve(vector<vector<int>>& graph,int l){
        if(l==graph.size()-1){
            res.push_back(v);
            return;
        }
        if(graph[l].empty())
            return;
        for(int i=0;i<graph[l].size();i++){
            v.push_back(graph[l][i]);
            solve(graph,graph[l][i]);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        solve(graph,0);
        return res;
    }
};