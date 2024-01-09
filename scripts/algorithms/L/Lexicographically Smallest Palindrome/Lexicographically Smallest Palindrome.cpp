// Runtime: 37 ms (Top 56.38%) | Memory: 15.40 MB (Top 63.28%)

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                char c = min(s[l], s[r]);
                s[l] = s[r] = c;
            }
            l++, r--;
        }
        return s;
    }
};
