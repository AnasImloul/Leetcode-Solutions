// Runtime: 34 ms (Top 83.45%) | Memory: 13.5 MB (Top 63.50%)
class Solution {
public:
    #define f first
    #define s second
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        priority_queue< array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        unordered_map<int, vector<pair<int,int>>> g;

        for(auto& f : flights){
            g[f[0]].push_back({f[1],f[2]});
        }
        vector<int> dis(n,INT_MAX);
        pq.push({0,src,0});
        while(!pq.empty()){
            int c = pq.top()[0];
            int cur = pq.top()[1];
            int lvl = pq.top()[2];
            pq.pop();
            if(cur==dst) return c;
            if(lvl > k || lvl >= dis[cur]) continue;
            dis[cur] = lvl;
            for(auto& nei : g[cur]){
                pq.push({c+nei.s, nei.f, lvl+1});
            }
        }
        return -1;
    }
};