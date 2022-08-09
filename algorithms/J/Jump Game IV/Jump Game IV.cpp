class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        if(arr.size()<=1) return 0;
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        int k = 1;
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node = q.front();
                q.pop();

                if(node+1<n and !vis[node+1]){
                    if(node+1==n-1) return k;
                    q.push(node+1);
                    vis[node+1]=true;
                }

                if(node-1>=0 and !vis[node-1]){
                    if(node-1==n-1) return k;
                    q.push(node-1);
                    vis[node-1]=true;
                }

                for(auto i:mp[arr[node]]){
                    if(i==node or vis[i]) continue;
                    if(i==n-1) return k;
                    q.push(i);
                    vis[i]=true;
                }
                
                mp[arr[node]].clear();
            }
            k++;
        }
        
        return -1;
    }
};
