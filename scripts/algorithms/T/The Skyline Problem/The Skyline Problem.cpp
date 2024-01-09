// Runtime: 23 ms (Top 78.66%) | Memory: 14.70 MB (Top 80.04%)

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> pq;
        vector<int> co;
        for (auto b:buildings) {
            co.push_back(b[0]);
            co.push_back(b[1]);
        }
        sort(co.begin(), co.end());
        int m = unique(co.begin(), co.end()) - co.begin();
        int j = 0, preH = 0;
        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            while (j<buildings.size() && buildings[j][0]<=co[i]) 
                pq.push(make_pair(buildings[j][2], buildings[j][1])), j++;
            while (!pq.empty() && pq.top().second<=co[i]) pq.pop();
            int nowH = pq.empty() ? 0 : pq.top().first;
            if (nowH != preH) {
                ans.push_back({co[i], nowH});
                preH=nowH;
            }
        }
        return ans;
    }
};
