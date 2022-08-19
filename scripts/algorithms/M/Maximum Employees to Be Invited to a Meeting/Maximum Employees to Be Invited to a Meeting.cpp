// Runtime: 489 ms (Top 53.58%) | Memory: 164.5 MB (Top 54.82%)

class Solution {
public:
    vector<vector<int>> rev;
    vector<int> es, sizeOfTwo;
    int N, ans1, ans2;
    void dfs(vector<int>& depth, int cur, int d) {
        if (depth[cur] > 0) {
            if (d - depth[cur] == 2) sizeOfTwo.push_back(cur);
            ans1 = max(ans1, d - depth[cur]);
            return;
        }
        if (depth[cur] != -1) return;
        depth[cur] = d;
        dfs(depth, es[cur], d+1);
        depth[cur] = 0; // 0 means visited
    }
    void findAllCircules() {
        vector<int> depth(N, -1);
        for (int i=0; i<N; i++) {
            if (depth[i] == -1) {
                dfs(depth, i, 1);
            }
        }
    }
    int dfs2(int cur, int except) {
        int ret = 1;
        int d = 0;
        for (auto nxt : rev[cur]) {
            if (nxt != except) {
                d = max(d, dfs2(nxt, except));
            }
        }
        return ret + d;
    }
    void expandSizeOfTwo() {
        for (auto i : sizeOfTwo) {
            int j = es[i];
            ans2 += dfs2(i, j);
            ans2 += dfs2(j, i);
        }
    }
    int maximumInvitations(vector<int>& favorite) {
        es = favorite;
        N = es.size(), ans1 = 0, ans2 = 0;
        rev.resize(N);
        for (int i=0; i<N; i++) {
            rev[es[i]].push_back(i);
        }
        findAllCircules();
        expandSizeOfTwo();
        return max(ans1, ans2);
    }
};