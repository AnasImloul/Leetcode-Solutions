class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<unordered_set<int>> v;
        for(auto i : wall) {
            int cs = 0;
            unordered_set<int> st;
            for(int j=0; j<i.size() - 1; j++) {
                cs += i[j];
                st.insert(cs);
            }
            v.push_back(st);
        }
        
        unordered_map<int, int> m;
        for(auto i : v) {
            for(auto j : i) m[j]++;
        }
        
        int mxfr = INT_MIN, mxel;
        for(auto i : m) {
            if(i.second > mxfr) mxel = i.first, mxfr = i.second;
        }
        
        int ans = 0;
        for(auto s : v) {
            if(s.find(mxel) == s.end()) ans++;
        }
        return ans;
    }
};
