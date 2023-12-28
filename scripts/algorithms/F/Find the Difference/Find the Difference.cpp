// Runtime: 0 ms (Top 100.0%) | Memory: 7.10 MB (Top 53.07%)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char cs : s) c ^= cs;
        for(char ct : t) c ^= ct;
        return c;
    }
};
