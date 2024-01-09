// Runtime: 61 ms (Top 67.96%) | Memory: 19.30 MB (Top 97.79%)

class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        if(n != m) return false;
        
        while(i < n || j < m) {
            while(i < n && s[i] == '_') i++;
            while(j < m && t[j] == '_') j++;
            
            if(s[i] != t[j]) return false;
            if(s[i] == 'R' && i > j) return false;
            if(s[i] == 'L' && i < j) return false;
            i++, j++;
        }
        return true;
    }
};
