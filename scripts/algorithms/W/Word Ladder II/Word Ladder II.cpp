// Runtime: 23 ms (Top 90.82%) | Memory: 9.9 MB (Top 40.33%)
class Solution {
public:
    map<string,vector<string>> parent;
    unordered_map<string,int> dist;
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         for(string node : wordList) dist[node] = INT_MAX , parent[node] = {};
         parent[beginWord] = {"root"};
         queue<string> q;
         dist[beginWord] = 1;
         q.push(beginWord);
         while(!q.empty()) {
             string par = q.front();
             q.pop();
             if(par==endWord) break;
             for(int i=0; i<par.size(); i++) {
                 string pref = "" , suff = "";
                 if(i) pref = par.substr(0,i);
                 if(i<par.size()-1) suff = par.substr(i+1);
                 string child = pref+'$'+suff;
                 int pos = pref.size();
                 for(char c='a'; c<='z'; c++) {
                       if(c!=par[i]) {
                            child[pos]=c;
                            if(dist.count(child)) {
                                 if(dist[child] > 1 + dist[par]) {
                                     dist[child] = 1 + dist[par];
                                     parent[child].clear(); // remove all parents , a better parent exists (shorter path from src to child)
                                     parent[child].push_back(par); // add that parent
                                     q.push(child);
                                 }else if(dist[child] == 1 + dist[par]) {
                                     parent[child].push_back(par); // add all parents of the best current distance
                                 }
                            }
                       }
                 }
             }
         }
         vector<string> path;
         pathfinder(endWord,path);
         for(int i=0; i<ans.size(); i++) reverse(ans[i].begin(),ans[i].end());
         return ans;
    }
    void pathfinder(string par,vector<string>&path) {
         if(par=="root") {
              ans.push_back(path); // no parent exists of the root node , add the path to answer
              return;
         }
         for(string node : parent[par]) {
              path.push_back(par);
              pathfinder(node,path);
              path.pop_back();
         }
    }
};