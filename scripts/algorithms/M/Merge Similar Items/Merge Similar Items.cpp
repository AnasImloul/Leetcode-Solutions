// Runtime: 72 ms (Top 16.98%) | Memory: 17.6 MB (Top 40.12%)
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> m;

        for(auto v : items1) m[v[0]] += v[1];
        for(auto v : items2) m[v[0]] += v[1];

        vector<vector<int>> ans;
        for(auto i : m) ans.push_back({i.first, i.second});

        return ans;
    }
};