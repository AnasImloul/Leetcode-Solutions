// Runtime: 3 ms (Top 100.00%) | Memory: 11.4 MB (Top 99.39%)
class Solution {
private:
    int countFreq(const string &s) {
        char c = *min_element(begin(s), end(s));
        return count(begin(s), end(s), c);
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqs(11, 0);
        for (const auto &word : words) {
            freqs[countFreq(word)]++;
        }
        vector<int> prefSum(12, 0);
        for (int i = 0; i < freqs.size(); i++) {
            prefSum[i+1] = prefSum[i] + freqs[i];
        }
        vector<int> ans;
        for (const auto &q : queries) {
            int cnt = countFreq(q);
            ans.push_back(prefSum.back() - prefSum[cnt + 1]);
        }
        return ans;
    }
};