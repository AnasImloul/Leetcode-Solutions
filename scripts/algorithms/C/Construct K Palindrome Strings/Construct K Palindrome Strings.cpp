class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        
        unordered_map<char, int> m;
        for(char c : s) m[c]++;
        
        int oddFr = 0;
        for(auto i : m) if(i.second % 2) oddFr++;
        
        return oddFr <= k;
    }
};
