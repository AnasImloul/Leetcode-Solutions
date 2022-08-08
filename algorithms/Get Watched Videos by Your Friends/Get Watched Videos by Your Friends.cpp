class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    vector<vector<int>>graph(watchedVideos.size());
    
    for(int i = 0;i != friends.size(); i++)
      for(auto &f: friends[i])
        graph[f].push_back(i), graph[i].push_back(f);
    
    int tmp_level = 0;
    vector<int>vis(watchedVideos.size(),0);
    vector<string>ans;
    
    queue<int>q;
    q.push(id);
    while(!q.empty()){
      if(tmp_level++ == level){
        unordered_map<string,int>mp;
        while(!q.empty()){
          int t = q.front(); q.pop();
          if(vis[t])continue;
          vis[t] = 1;
          for(auto &v: watchedVideos[t]) mp[v]++;
        }
        set<pair<int,string>>st;  
        for(auto &[s, n]: mp) st.insert({n,s});
        for(auto &it: st) ans.push_back(it.second);
      }
                    
      int n = q.size();
      while(n--){
        int t = q.front(); q.pop();
        if(vis[t])continue;
        vis[t] = 1;
        
        for(auto &x: graph[t])
          if(!vis[x]) q.push(x);
      }
    }
    
    return ans;
  }
};
