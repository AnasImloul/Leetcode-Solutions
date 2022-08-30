// Runtime: 35 ms (Top 93.71%) | Memory: 19.1 MB (Top 51.70%)
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        for (auto& s : words1) ++freq1[s];
        for (auto& s : words2) ++freq2[s];
        int ans = 0;
        for (auto& [s, v] : freq1)
            if (v == 1 && freq2[s] == 1) ++ans;
        return ans;
    }
};