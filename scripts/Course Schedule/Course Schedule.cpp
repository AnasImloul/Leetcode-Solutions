class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>>adj;
        vector<int> indegree(numCourses,0);
        vector<int>res;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(auto u:adj[x]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        return res.size()==numCourses;
        
    }
};