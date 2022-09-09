// Runtime: 8 ms (Top 38.89%) | Memory: 6.6 MB (Top 89.52%)
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) freq[c]++;
        int val = freq[s[0]];
        for (auto [a, b] : freq) if (b != val) return false;
        return true;
    }
};