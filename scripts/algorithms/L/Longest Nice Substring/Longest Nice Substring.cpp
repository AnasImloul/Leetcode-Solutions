class Solution {
public:
    bool isNiceSubstring(string& s, int i, int j) {
        unordered_map<int, bool> mp;
        bool isTrue = true;
        for (int x = i; x <= j; x++) {
            mp[s[x]] = true;
        }
        
        while (i <= j) {
            if (s[i] < 97) {
                if (!mp[s[i] + 32]) {
                    return false;
                }
            } else {
                if (!mp[s[i] - 32]) {
                    return false;
                }
            }
            i++;
        }
        
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        string result;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isNiceSubstring(s, i, j)) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        
        return result;
    }
};
