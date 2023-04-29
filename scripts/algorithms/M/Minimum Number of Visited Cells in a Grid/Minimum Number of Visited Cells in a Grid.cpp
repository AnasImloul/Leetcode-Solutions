static constexpr int INF = 1e9;

struct Sweep {
    int pos = 0;
    map<int, int> vs;
    vector<vector<int>> del;  
    // ^^ use vector instead of unordered_map, since it's much faster
    Sweep(int sz) : del(sz) {}
    inline void add(int v, int end_pos) {
        ++vs[v];
        if (end_pos < del.size())  // if >, dont need to delete
            del[end_pos].push_back(v);
    }
    inline int get() {
        if (vs.empty()) return INF;  // can't reach.
        return begin(vs)->first;     // get minimum
    }
    inline void advance() {
        for (int v : del[pos])
            if (--vs[v] == 0)
                vs.erase(v);
        ++pos;
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        vector<Sweep> vert(M, Sweep(N));
        for (int r = 0; r < N; ++r) {
            Sweep hori(M);  // this is hori[r]
            for (int c = 0; c < M; ++c) {
                int hr = hori.get();
                int vt = vert[c].get();
                int v = 1 + min(hr, vt);
                if (r == 0 && c == 0) v = 1;
                if (v < INF) {
                    if (r == N-1 && c == M-1) return v;
                    int dx = grid[r][c];
                    hori.add(v, c + dx);
                    vert[c].add(v, r + dx);
                }
                hori.advance();
                vert[c].advance();
            }
        }
        return -1;
    }
};