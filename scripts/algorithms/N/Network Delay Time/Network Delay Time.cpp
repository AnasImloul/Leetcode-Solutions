// Runtime: 220 ms (Top 41.81%) | Memory: 44.6 MB (Top 18.95%)
class cmp{
  public:
    bool operator()(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second>b.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> a[n];
        for(auto it:times)
        {
            a[it[0]-1].push_back({it[1]-1,it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        vector<int> dist(n,1e7);

        pq.push({k-1,0});

        vector<int> vis(n,0);
        while(pq.size())
        {
            auto curr = pq.top();
            pq.pop();

            int v = curr.first;
            int w = curr.second;

            if(vis[v])continue;

            vis[v] = 1;
            dist[v] = w;
            for(auto it:a[v])
            {
                if(vis[it.first]==0)
                {
                    pq.push({it.first,it.second + w});
                }
            }
        }

        int mx = INT_MIN;
        for(auto it:dist)
            mx = max(mx,it);

        if(mx>=1e7)return -1;
        return mx;

    }
};