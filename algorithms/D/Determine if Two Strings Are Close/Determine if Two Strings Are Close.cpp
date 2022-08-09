class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<int> w1_letters, w2_letters, w1_freq, w2_freq;
        unordered_map<char, int> w1_m, w2_m;
        
        for (auto a : word1) {
            w1_letters.insert(a);
            w1_m[a]++;
        }
        
        for (auto a : word2) {
            w2_letters.insert(a);
            w2_m[a]++;
        }
        
        for (auto [k, v] : w1_m) w1_freq.insert(v);
        
        for (auto [k, v] : w2_m) w2_freq.insert(v);

        return w1_letters == w2_letters && w1_freq == w2_freq;
    }
};
