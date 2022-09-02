// Runtime: 777 ms (Top 43.05%) | Memory: 144.4 MB (Top 61.85%)
class Solution {
public:
    vector<int> parents;
    vector<int> ranks;
    int find(int a) {
        if (a == parents[a])
            return parents[a];
        return parents[a] = find(parents[a]);
    }

    void uni(int a, int b) {
        a = find(a);
        b = find(b);

        if (ranks[a] >= ranks[b]) {
            parents[b] = a;
            ranks[a]++;
        }
        else {
            parents[a] = b;
            ranks[b]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        ranks = vector<int>(n, 0);

        for (int i = 0; i < n; i++) {
            parents.push_back(i);
        }

        for (auto &v : allowedSwaps)
            uni(v[0], v[1]);
        vector<unordered_multiset<int>> subs(n);

        for (int i = 0; i < n; i++) {
            subs[find(i)].insert(source[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!subs[parents[i]].count(target[i]))
                cnt++;
            else
                subs[parents[i]].erase(subs[parents[i]].find(target[i]));
        }
        return cnt;
    }
};