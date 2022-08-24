// Runtime: 18 ms (Top 59.02%) | Memory: 9.7 MB (Top 71.88%)
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for (auto const &s: sentences) {
            int n = count(s.begin(), s.end(), ' ');
            res = max(res, n + 1);
        }
        return res;
    }
};