class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int m = s.length(), n = t.length(), count = 0;
        if (m != n) return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            if (t[i] == s[i]) continue;
            int diff = t[i] - s[i] < 0 ? 26 + t[i] - s[i] : t[i] - s[i];
            if (mp.find(diff) == mp.end()) {
                count = max(count, diff);
            } else {
                count = max(count, (mp[diff] * 26) + diff);
            }
            mp[diff]++;
            if (count > k) return false;
        }
        return count <= k;
    }
    
}; 
