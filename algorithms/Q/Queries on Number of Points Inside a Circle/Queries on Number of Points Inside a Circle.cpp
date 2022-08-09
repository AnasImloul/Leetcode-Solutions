class Solution {
    void buildTree(vector<vector<int>>& p, int depth, int i, int j) {
        if (j - i <= 1) return;
        
        int k = 1 - depth & 1, m = i + (j - i) / 2;
        nth_element(p.begin() + i, p.begin() + m, p.begin() + j,
                    [k](auto &a, auto& b) { return a[k] < b[k]; });
        partition(p.begin() + i, p.begin() + j,
                  [k, m, &p](auto &a){ return a[k] < p[m][k]; });

        buildTree(p, depth+1, i, m);
        buildTree(p, depth+1, m+1, j);
    }
    
    inline bool isPointInside(const vector<int> &p, const vector<int> &c) {
        return (p[0] - c[0]) * (p[0] - c[0]) + (p[1] - c[1]) * (p[1] - c[1]) <= c[2] * c[2];
    }

    int pointsInside(const vector<vector<int>> &t, const vector<int> &q, int depth,
                    int i, int j) {
        if (j == i) return 0;
        else if (j - i == 1) return isPointInside(t[i], q);
        
        int k = 1 - depth & 1, m = i + (j - i) / 2, diff = t[m][k] -  q[k];
        if (diff > q[2]) return pointsInside(t, q, depth+1, i, m);
        else if (diff < -q[2]) return pointsInside(t, q, depth+1, m+1, j);
        else
            return pointsInside(t, q, depth+1, i, m)
                + isPointInside(t[m], q)
                + pointsInside(t, q, depth+1, m+1, j);
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        buildTree(points, 0, 0, points.size());

        vector<int> res(queries.size());
        for (size_t i = 0; i < queries.size(); ++i)
            res[i] = pointsInside(points, queries[i], 0, 0, points.size());
        return res;
    }
};
