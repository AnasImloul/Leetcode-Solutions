class Solution {
    vector<int> ans;
    vector<vector<int>> graph;
    string global;
public:
    
    
    vector<int> getAns(int u, int parent){
        ans[u] = 1;
        char rootChar = global[u];
        vector<int> toReturn = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        
        for(int adj : graph[u]){
            if(adj != parent){
                vector<int> c = getAns(adj, u);
                for(int i = 0 ; i < 26 ; i++){
                    toReturn[i] += c[i];
                } 
                ans[u] += c[rootChar-'a'];
            }
            
        }
        toReturn[rootChar-'a'] += 1;
        return toReturn;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        graph.resize(n);
        global = labels;
        
        
        
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        int parent =  -1;  
        getAns(root, parent);
        return ans;
 
    }
};
