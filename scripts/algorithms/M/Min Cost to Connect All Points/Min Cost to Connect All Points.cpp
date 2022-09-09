// Runtime: 2345 ms (Top 8.82%) | Memory: 175.8 MB (Top 19.01%)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = points.size();
        priority_queue<vector<int>> q;
        unordered_set<int> vis;
        int ans = 0;
        q.push({0,0,0});
        vector<int> cur;
        while(!q.empty() && vis.size()<n){
            cur = q.top(); q.pop();
            if(vis.count(cur[2]))continue;
            ans += -cur[0];
            vis.insert(cur[2]);
            for(int i=0;i<n;i++){
                if(!vis.count(i)){
                    int d = abs(points[cur[2]][0] - points[i][0]) +
                        abs(points[cur[2]][1] - points[i][1]);
                    q.push({-d,cur[2],i});
                }
            }
        }
        return ans;
    }
};