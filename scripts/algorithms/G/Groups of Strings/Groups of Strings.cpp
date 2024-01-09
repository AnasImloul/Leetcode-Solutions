// Runtime: 660 ms (Top 81.82%) | Memory: 149.30 MB (Top 51.14%)

// OJ: https://leetcode.com/problems/groups-of-strings/
// Author: github.com/lzl124631x
// Time: O(26 * N * alpha(N))
// Space: O(26 * N)
class UnionFind {
    vector<int> id, rank, size;
    int cnt;
public:
    UnionFind(int n) : id(n), rank(n, 0), size(n, 1), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            id[y] = x;
            size[x] += size[y];
        } else {
            id[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
        --cnt;
    }
    int getSize(int a) {
        return size[find(a)];
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    vector<int> groupStrings(vector<string>& A) {
        int N = A.size();
        UnionFind uf(N);
        unordered_map<int, int> m, delMap;
        m.reserve(N);
        for (int i = 0; i < N; ++i) {
            int h = 0;
            for (char c : A[i]) h |= 1 << (c - 'a'); // `h` is the bitmask representation of `A[i]`
            for (int j = 0; j < 26; ++j) {
                if (h >> j & 1) { // if `h`'s j-th bit is 1
                    int del = h ^ (1 << j); // `del` is the bitmask after deleting the `j`-th bit
                    if (m.count(del)) uf.connect(i, m[del]); // Connect `A[i]` with its deletion variant
                    if (delMap.count(del)) uf.connect(i, delMap[del]);
                    else delMap[del] = i;
                } else {
                    int add = h | (1 << j); // `add` is the bitmask after adding `j`-th bit
                    if (m.count(add)) uf.connect(i, m[add]);
                }
            }
            m[h] = i;
        }
        int mx = 1;
        for (int i = 0; i < N; ++ i) mx = max(mx, uf.getSize(i));
        return {uf.getCount(), mx};
    }
};
