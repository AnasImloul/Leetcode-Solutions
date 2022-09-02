// Runtime: 1335 ms (Top 26.39%) | Memory: 149.2 MB (Top 71.30%)
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        const int n = rooms.size(), m = queries.size();
        for(int i = 0; i < m; i++) queries[i].push_back(i);
        sort(begin(queries), end(queries), [](const auto& a, const auto& b){return a[1] > b[1];});
        sort(begin(rooms), end(rooms), [](const auto& a, const auto& b){return a[1] > b[1];});
        vector<int> ans(m, -1);
        set<int> ids;
        int j = 0;
        for(const auto& q: queries){
            while(j < n && rooms[j][1] >=q[1]) ids.insert(rooms[j++][0]);
            if(ids.empty()) continue;
            int id = q[0];
            auto it = ids.lower_bound(id);
            int id1 = (it != end(ids) )? *it : INT_MAX;
            int id2 = id1;
            if(it != begin(ids)) id2 = *prev(it);
            ans[q[2]] = abs(id1 - id) < abs(id2 - id) ? id1 : id2;
        }
        return ans;
    }
};