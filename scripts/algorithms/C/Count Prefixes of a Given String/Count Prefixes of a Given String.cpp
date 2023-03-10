class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = words.size();

        for (auto && word : words) {
            for (int i = 0; i < word.size(); i++) {
                if (s[i] != word[i]) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};