// Runtime: 22 ms (Top 25.79%) | Memory: 7.4 MB (Top 47.98%)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s != t)
            return false;

        return true;
    }
};