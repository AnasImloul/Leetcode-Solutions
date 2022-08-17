class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<vector<int>> line; 
        for (auto& f : flowers) {
            line.push_back({f[0], +1}); 
            line.push_back({f[1]+1, -1}); 
        }
        sort(line.begin(), line.end()); 
        int prefix = 0; 
        vector<int> time, vals; 
        for (auto& l : line) {
            time.push_back(l[0]); 
            vals.push_back(prefix += l[1]); 
        }
        vector<int> ans; 
        for (auto& p : persons) {
            auto it = upper_bound(time.begin(), time.end(), p); 
            if (it == time.begin()) ans.push_back(0); 
            else ans.push_back(vals[it - time.begin() - 1]); 
        }
        return ans; 
    }
};
