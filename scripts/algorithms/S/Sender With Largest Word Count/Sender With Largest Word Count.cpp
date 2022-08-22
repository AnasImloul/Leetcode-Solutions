// Runtime: 428 ms (Top 34.44%) | Memory: 77.6 MB (Top 40.48%)
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        int n(size(messages));
        map<string, int> m;
        for (auto i=0; i<n; i++) {

            stringstream ss(messages[i]);
            string word;
            int count(0);
            while (ss >> word) count++;
            m[senders[i]] += count;
        }

        int count(0);
        string res;
        for (auto& p : m) {
            if (p.second >= count) {
                count = p.second;
                if (!res.empty() or res < p.first) res = p.first;
            }
        }
        return res;
    }
};