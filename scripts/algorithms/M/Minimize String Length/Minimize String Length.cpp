// Runtime: 0 ms (Top 100.0%) | Memory: 8.00 MB (Top 89.61%)

class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> v(26,0);
        int ans = 0;
        for(auto &i: s){
            if(!v[i-'a']){
                ans++;
                v[i-'a'] = true;
            }
        }
        return ans;
    }
};
