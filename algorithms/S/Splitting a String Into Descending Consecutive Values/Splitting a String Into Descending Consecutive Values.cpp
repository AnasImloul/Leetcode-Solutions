class Solution {
    bool helper(string s, long long int tar) {
        if (stoull(s) == tar) return true;
        for (int i = 1; i < s.size(); ++i) {
            if (stoull(s.substr(0, i)) != tar)    continue;
            if (helper(s.substr(i, s.size()-i), tar-1))
                return true;
        }
        return false;
    }
public:
    bool splitString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            long long int tar = stoull(s.substr(0, i));
            if (helper(s.substr(i, s.size()-i), tar-1))
                return true;
        }
        return false;
    }
};
