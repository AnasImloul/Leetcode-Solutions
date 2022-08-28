// Runtime: 889 ms (Top 66.36%) | Memory: 18.1 MB (Top 68.98%)
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {

        int m(size(s)), n(size(sub));
        unordered_map<char, unordered_set<char>> mp;

        auto doit = [&](int ind) {

            for (int i=ind, j=0; i<ind+n; i++, j++) {
                if (s[i] == sub[j] or mp[sub[j]].count(s[i])) continue;
                return false;
            }
            return true;
        };

        for (auto& mapping : mappings) mp[mapping[0]].insert(mapping[1]);;
        for (int i=0; i<=m-n; i++) if (doit(i)) return true;
        return false;
    }
};