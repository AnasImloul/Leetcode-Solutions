// Runtime: 35 ms (Top 53.02%) | Memory: 13.1 MB (Top 84.47%)
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        stack<pair<int, int>> st;
        for (auto& l : logs) {
            auto p1 = l.find(':', 0), p2 = l.find(':', p1+1);
            auto id = stoi(l.substr(0, p1));
            auto time = stoi(l.substr(p2+1));
            if (l[p1+1] == 's') {
                st.push({id, time});
            } else {
                auto diff = time - st.top().second + 1;
                ret[st.top().first] += diff;
                st.pop();
                if (!st.empty())
                    ret[st.top().first] -= diff;
            }
        }
        return ret;
    }
};