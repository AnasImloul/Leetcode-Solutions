// Runtime: 97 ms (Top 54.91%) | Memory: 10.70 MB (Top 62.14%)

class Solution {
public:
    bool similar(string &s,string &t){
        int dif=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                dif++;
            }
        }
        return dif<=2;
    }
    void dfs(int node,vector<int>&vis,vector<vector<int>>&graph){
        vis[node]=1;
        for(auto&child:graph[node]){
            if(!vis[child]){
                dfs(child,vis,graph);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>graph(strs.size());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(similar(strs[i],strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph);
                ans++;
            }
        }
        return ans;
    }
};
