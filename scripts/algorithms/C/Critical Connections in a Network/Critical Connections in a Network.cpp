// Runtime: 1262 ms (Top 24.62%) | Memory: 179.7 MB (Top 55.22%)
class Solution {
public:
    vector<vector<int>>ans;

    void dfs(vector<vector<int>>&graph , int node , int parent , vector<bool>&vis , int& ct , vector<int>&time , vector<int>&low){
        vis[node] = 1;
        time[node] = ct;
        low[node] = ct++;
        for(auto value : graph[node]){
            if(value == parent)continue;
            if(!vis[value]){
                dfs(graph , value , node , vis , ct , time , low);
                low[node] = min(low[node] , low[value]);

                if(low[value] > time[node]){
                    ans.push_back({node , value});
                }
            }else{
                low[node] = min(low[node] , time[value]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ans.clear();
        vector<vector<int>>graph(n);

        for(int i = 0 ; i < connections.size() ; i += 1){
            int a = connections[i][0];
            int b = connections[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool>vis(n , false);
        vector<int>time(n , -1);
        vector<int>low(n , -1);
        int ct = 0;
        for(int i = 0 ; i < n ; i += 1){
            if(!vis[i]){
                dfs(graph , i , -1 , vis , ct , time , low);
            }
        }

        return ans;
    }
};