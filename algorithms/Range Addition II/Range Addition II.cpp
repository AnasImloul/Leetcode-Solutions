class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
     
        int mn_i = m, mn_j = n;
        for(auto &i : ops)
            mn_i = min(mn_i, i[0]), mn_j = min(mn_j, i[1]);
        
        return mn_i * mn_j;
    }
};
