class Solution {
public:
    
    bool dfs(vector<int>adj[], vector<int>& color, int node){
        for(auto it: adj[node]){ //dfs over adjacent nodes
            if(color[it]==-1){ //not visited yet
                color[it]=1-color[node]; //set different color of adjacent nodes 
                if(!dfs(adj,color,it)) return false;
            }
            else if(color[it]!=1-color[node]) return false; //if adjacent nodes have same color
        }
        return true;
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){//undirected graph
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>color(n+1,-1); //-1 i.e. not visited yet
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(adj,color,i)) return false;
            }
        }
        return true;
    }
};

