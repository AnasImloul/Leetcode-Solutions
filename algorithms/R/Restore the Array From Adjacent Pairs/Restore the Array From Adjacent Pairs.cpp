class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp, unordered_map<int,bool> &visited, int sv, vector<int> &ans){
        for(auto x:mp[sv]){
            if(!visited[x]){
                visited[x]=true;
                ans.push_back(x);
                dfs(mp,visited,x,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int,bool> visited;
        unordered_map<int,vector<int>> mp;
        for(auto x:adjacentPairs){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        int start_node;
        for(auto x:mp){
            if(x.second.size()==1){
                start_node=x.first;
                break;
            }
        }
        visited[start_node]=true;
        ans.push_back(start_node);
        dfs(mp,visited,start_node,ans);
        return ans;
    }
};
