class Solution {
public:
    void setPermutations(const string& s, queue<pair<string, int>>& q, int count) {
        for (int i=0; i<4; i++) {
            int j = s[i]-'0';
            char b = (10+j-1)%10 + '0', n = (10+j+1)%10 + '0';
            auto tmp = s; tmp[i]=b;
            q.push({tmp, count+1});
            tmp = s; tmp[i]=n;
            q.push({tmp, count+1});
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadies(deadends.begin(), deadends.end());
        queue<pair<string, int>> q({{"0000", 0}});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (deadies.count(t.first))
                continue;
            if (t.first==target)
                return t.second;
            deadies.insert(t.first);
            setPermutations(t.first, q, t.second);
        }
        return -1;
    }
};
