class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> umap(101);
        for (auto &r: rectangles) {
            umap[r[1]].push_back(r[0]);
        }
        
        for (int i = 0; i < 101; i++) {
            sort(begin(umap[i]), end(umap[i]));
        }
        
        vector<int> res;
        for (auto &p: points) {
            int sum = 0;
            for (int i = p[1]; i < 101; i++) {
                auto lb = lower_bound(begin(umap[i]), end(umap[i]), p[0]);
                sum += end(umap[i]) - lb;
            }
            res.push_back(sum);
        }
        return res;
    }
};
