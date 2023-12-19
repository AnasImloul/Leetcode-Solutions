// Runtime: 478 ms (Top 64.22%) | Memory: 188.50 MB (Top 37.62%)

class Solution {
    long long sqr(long long x) {
        return x * x;
    }

public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        const int n = items.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return items[x][0] > items[y][0];
        });
        unordered_map<int, int> num;
        priority_queue<pair<int, int>> q;
        long long v = 0;
        for (int i = 0; i < k; ++i) {
            v += items[ind[i]][0];
            ++num[items[ind[i]][1]];
            q.push({-items[ind[i]][0], ind[i]});
        }
        long long r = v + sqr(num.size());
        for (int i = k; i < n && !q.empty(); ++i) {
            if (num.count(items[ind[i]][1])) {
                continue;
            }
            const int x = q.top().second;
            q.pop();
            if (num[items[x][1]] == 1) {
                --i;
                continue;
            }
            v += items[ind[i]][0] - items[x][0];
            --num[items[x][1]];
            ++num[items[ind[i]][1]];
            r = max(r, v + sqr(num.size()));
        }
        return r;
    }
};
