// Runtime: 86 ms (Top 97.61%) | Memory: 26.9 MB (Top 59.63%)
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const auto n = word.size();

        int cnt = 1;
        int len = 1;
        int max_len = 0;
        for (int i = 1; i != n; ++i) {
            if (word[i - 1] == word[i]) {
                ++len;
            } else if (word[i - 1] < word[i]) {
                ++len;
                ++cnt;
            } else {
                cnt = 1;
                len = 1;
            }

            if (cnt == 5) {
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};